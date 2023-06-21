#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"
#include "../include/form.h"

#include <locale.h>
#include <string>

#include <iostream>
#include <iomanip>

// getting terminal width
#include <sys/ioctl.h>
#include <stdio.h>

#include <unistd.h>
#include <termios.h>

char getch()
{
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return (buf);
}

const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "December"};
const int KEY_RIGHT = 'C';
const int KEY_LEFT = 'D';
const int KEY_UP = 'A';
const int KEY_DOWN = 'B';

Calendar::Calendar()
{
  setlocale(LC_ALL, "");

  bool quit = false;

  while (!quit)
  {
    updateDisplay();

    int input = getch();

    switch (input)
    {
    case 'a':
      setDisplayMode(0);
      break;
    case 'w':
      setDisplayMode(1);
      break;
    case 'd':
      setDisplayMode(2);
      break;
    case 's':
      setDisplayMode(3);
      break;
    case 'c':
      setDisplayMode(4);
      break;
    case 'e':
      setDisplayMode(5);
      break;
    case 'x':
      setDisplayMode(6);
      break;
    case '\n':
      setDisplayMode(7);
      break;
    case 'b':
      setDisplayMode(previousDisplayMode);
      break;
    case 'q':
      quit = true;
      break;
    case '\033':
      getch();
      switch (getch())
      {
      case KEY_RIGHT:
        nextDay(today);
        break;
      case KEY_LEFT:
        previousDay(today);
        break;
      case KEY_DOWN:
        nextWeek(today);
        break;
      case KEY_UP:
        previousWeek(today);
        break;
      default:
        break;
      }
    }
  }
}

void Calendar::nextDay(Date &date)
{
  if (!date.setDay(date.getDay() + 1))
  {
    date.setMonth(date.getMonth() + 1);
    date.setDay(1);
  }
}

void Calendar::previousDay(Date &date)
{
  if (!date.setDay(date.getDay() - 1))
  {
    date.setMonth(date.getMonth() - 1);

    if (!date.setDay(31))
      if (!date.setDay(30))
        if (!date.setDay(29))
          date.setDay(28);
  }
}

void Calendar::nextWeek(Date &date)
{
  if (!date.setDay(date.getDay() + 7))
  {
    date.setMonth(date.getMonth() + 1);
    int current_week = date.getWeekDayNumber();
    for (int i = 1; i < 7; i++)
    {
      date.setDay(i);
      if (date.getWeekDayNumber() == current_week)
        break;
    }
  }
}

void Calendar::previousWeek(Date &date)
{
  if (!date.setDay(date.getDay() - 7))
  {
    date.setMonth(date.getMonth() - 1);
    int current_week = date.getWeekDayNumber();
    for (int i = 31; i > 21; i--)
    {
      if (!date.setDay(i))
        continue;

      if (date.getWeekDayNumber() == current_week)
        break;
    }
  }
}

void Calendar::setDisplayMode(int layout)
{
  previousDisplayMode = current_layout;
  current_layout = layout;
}

void Calendar::updateDisplay()
{
  std::system("clear");

  switch (current_layout)
  {
  case 0:
    getMonthView(today);
    getHelpView();
    break;
  case 1:
    getWeekView(today);
    getHelpView();
    break;
  case 2:
    getDayView(today, now);
    getHelpView();
    break;
  case 3:
    getScheduleView(today);
    getHelpView();
    break;
  case 4:
    createEventView(today);
    break;
  case 5:
    editEventView(today);
    break;
  case 6:
    deleteEventView(today);
    break;
  case 7:
    getSelectedEvent(today);
    getHelpView();
    break;
  default:
    getScheduleView(today);
    break;
  }
}

void Calendar::createEvent(Event &event)
{
  events.push_back(event);
}

bool Calendar::deleteEvent(Event &event)
{
  for (int i = 0; i < events.size(); i++)
    if (events[i] == event)
    {
      events.erase(events.begin() + i);
      return true;
    }

  return false;
}

bool Calendar::editEvent(Event &event)
{
  for (int i = 0; i < events.size(); i++)
    if (events[i] == event)
    {
      // TODO Impl edit function

      return true;
    }

  return false;
}

std::vector<Event> Calendar::getEvents(Date &date)
{
  return events;
}

// Generally, month switching doens't work on new year's Dec-Jan
// TODO: Impl setMonth() logic checks & year switching
void Calendar::getMonthView(Date &date)
{
  const char *week_placeholder = "Sun Mon Tue Wed Thu Fri Sat";

  int header_length = std::string(months[date.getMonth() - 1]).length() + 5;
  int required_spaces = (27 - header_length) / 2;
  std::string spacing;

  for (int i = 0; i < required_spaces; i++)
    spacing += " ";

  std::cout << spacing << months[date.getMonth() - 1] << " " << date.getYear() << std::endl;
  std::cout << week_placeholder << std::endl;
  Date first_day_of_the_month(1, date.getMonth(), date.getYear());
  int first_day = first_day_of_the_month.getWeekNumber();
  Date last_month(1, date.getMonth() - 1, date.getYear()); // this is borked if it's January

  Date last_sunday = last_month;
  for (int i = 1; i <= days_in_month(last_month); i++)
  {
    if (last_month.getWeekDayNumber() == 0)
      last_sunday = last_month;

    last_month.setDay(i);
  }

  Date temp_date(date);

  std::vector<Event> events_this_month;

  int day = last_sunday.getDay();
  bool first_iteration = true;
  bool last_iteration = true;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (!first_iteration && !temp_date.setDay(day))
      {
        day = 1;
        last_iteration = false;
      }

      if (first_iteration && !last_month.setDay(day))
      {
        day = 1;
        first_iteration = false;
      }

      if (!first_iteration && last_iteration && day == date.getDay())
      {
        std::cout << "\033[1;44m" << std::setw(3) << day << " "
                  << "\033[0m";
      }
      // else if (events.size() > 0)
      // {
      //   for (int i = 0; i < events.size(); i++)
      //   {
      //     if (events[i].getStartDate().getMonth() == date.getMonth() && events[i].getStartDate().getYear() == date.getYear())
      //     {
      //       if (events[i].getStartDate().getDay() == day)
      //       {
      //         std::cout << "\033[1;43m" << std::setw(3) << day << " "
      //                   << "\033[0m";
      //       }
      //     }
      //   }
      // }
      else
      {
        std::cout << std::setw(3) << day << " ";
      }

      day++;
    }
    std::cout << std::endl;
  }
}

void Calendar::getWeekView(Date &date)
{
  int header_length = std::string(months[date.getMonth() - 1]).length() + 12;
  int required_spaces = (27 - header_length) / 2;
  std::string spacing = "";

  for (int i = 0; i < required_spaces; i++)
    spacing += " ";

  std::cout << spacing << "Week " << date.getWeekNumber() << " - " << months[date.getMonth() - 1] << " " << date.getYear() << std::endl;

  Date temp_date = date;

  std::vector<Event> events_today;

  for (Event event : events)
  {
    if (event.getStartDate() == date)
      events_today.push_back(event);
  }

  for (int i = 0; i < 7; i++)
  {
    std::cout << temp_date.getWeekDay() << " " << std::setw(2) << temp_date.getDay() << " | "
              << "no events for today" << std::endl;
    if (!temp_date.setDay(temp_date.getDay() + 1))
    {
      temp_date.setDay(1);
      temp_date.setMonth(temp_date.getMonth() + 1);
    }
  }
}

void Calendar::getDayView(Date &date, Time &time)
{
  std::cout << date.getWeekDay() << " " << months[date.getMonth() + 1] << " " << date.getDay() << " " << date.getYear() << std::endl;

  Time temp_time = time;
  Date temp_date = date;

  for (int i = 0; i < 7; i++)
  {
    std::cout << std::setw(2) << temp_time.getHour() << ":00 | "
              << "no events for now" << std::endl;
    if (!temp_time.setHour(temp_time.getHour() + 1))
    {
      temp_time.setHour(0);
      if (!temp_date.setDay(temp_date.getDay() + 1))
      {
        temp_date.setDay(1);
        temp_date.setMonth(temp_date.getMonth() + 1);
      }
    }
  }
}

void Calendar::getScheduleView(Date &date)
{
  std::vector<Event> events_today;
  std::vector<Event> events_upcoming;

  for (Event event : events)
  {
    if (event.getStartDate() == date)
      events_today.push_back(event);

    if (event.getStartDate() > date)
      events_upcoming.push_back(event);
  }

  if (events_today.empty())
  {
    std::cout << date.getWeekDay() << " " << months[date.getMonth() - 1] << " " << date.getDay() << " | no events for today" << std::endl;
  }
  else if (events_today.size() == 1)
  {
    std::cout << date.getWeekDay() << " " << months[date.getMonth() - 1] << " " << date.getDay() << " | " << events[0].getName() << std::endl;
  }
  else
  {
    std::cout << date.getWeekDay() << " " << months[date.getMonth() - 1] << " " << date.getDay() << " | " << events[0].getName() << " and " << (events_today.size() - 1) << " more..." << std::endl;
  }

  int max_schedule_length = (events_upcoming.size() <= 6) ? events_upcoming.size() : 6;

  for (int i = 0; i < max_schedule_length; i++)
  {
    Event event = events_upcoming[i];

    std::cout << event.getStartDate().getWeekDay() << " " << months[event.getStartDate().getMonth() - 1] << " " << event.getStartDate().getDay() << " | " << event.getName() << std::endl;
  }
}

void Calendar::createEventView(Date &date)
{
  std::cout << "Create new event" << std::endl
            << std::endl;

  std::string str = "";
  Date today;
  Time now;
  Color color;
  Event event(str, today, now, today, now, color, str);

  Form::createDialogBox(event);

  events.push_back(event);

  setDisplayMode(0);
  updateDisplay();
}

void Calendar::editEventView(Date &date)
{
  std::cout << "Edit an existing event" << std::endl
            << std::endl;

  std::string event_id;

  getSelectedEvent(date);

  std::cout << "Provide event id: ";
  std::getline(std::cin, event_id);

  try
  {
    Form::createDialogBox(events[std::stoi(event_id) - 1]);
  }
  catch (std::exception &e)
  {
  }

  setDisplayMode(0);
  updateDisplay();
}

void Calendar::deleteEventView(Date &date)
{
  std::cout << "Remove an existing event" << std::endl
            << std::endl;

  int event_id;

  getSelectedEvent(date);

  try
  {
    std::cout << "Provide event id: ";
    std::cin >> event_id;
  }
  catch (std::exception &e)
  {
  }

  events.erase(events.begin() + event_id - 1);

  setDisplayMode(0);
  updateDisplay();
}

void Calendar::getSelectedEvent(Date &date)
{
  std::cout << "Event details: " << std::endl;
  int temp_id = 1;

  for (auto event : events)
  {
    auto sDate = event.getStartDate();
    auto sTime = event.getStartTime();
    auto eDate = event.getEndDate();
    auto eTime = event.getEndTime();

    auto color = event.getColor();
    std::stringstream color_stream;
    color_stream << std::hex << (color.getRed() << 16 | color.getGreen() << 8 | color.getBlue());

    std::cout << temp_id << ") " << std::endl
              << "Name: " << event.getName() << std::endl
              << "Starts: " << sDate.getMonth() << "/" << std::setfill('0') << std::setw(2) << sDate.getDay() << "/" << sDate.getYear() << " "
              << std::setw(2) << sTime.getHour() << ":" << std::setfill('0') << std::setw(2) << sTime.getMinute() << std::endl
              << "Ends: " << eDate.getMonth() << "/" << std::setfill('0') << std::setw(2) << eDate.getDay() << "/" << eDate.getYear() << " "
              << std::setw(2) << eTime.getHour() << ":" << std::setfill('0') << std::setw(2) << eTime.getMinute() << std::endl
              << "Color: #" << color_stream.str() << std::endl
              << "Notes: " << event.getNotes() << std::endl
              << std::endl
              << std::setfill(' ');

    temp_id++;
  }
}

void Calendar::getHelpView()
{
  // terminal colums get
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  const int COLS = w.ws_col;

  std::cout << std::string(COLS, '-') << std::endl;

  std::cout << "→ - next day            "
            << "← - previous day         "
            << "↑ - next week              "
            << "↓ - previous week"
            << std::endl
            << "a - month view          "
            << "w - week view            "
            << "d - day view               "
            << "s - schedule view"
            << std::endl
            << "c - create a new event  "
            << "e - edit selected event  "
            << "x - delete selected event"
            << std::endl
            << "Enter - show details    "
            << "b - go back              "
            << "q - quit"
            << std::endl;
}

int Calendar::days_in_month(Date &date)
{
  int month = date.getMonth();
  if (month == 2)
  {
    if (Date::isLeapYear(date.getYear()))
      return 29;

    return 28;
  }

  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;

  return 31;
}