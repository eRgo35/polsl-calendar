#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"
#include "../include/form.h"
#include "../include/file.h"

#include <locale.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fstream>
#include <list>
#include <map>

// Function for reading characters from terminal without the need of pressing Enter (character capture function)
// Code found, on the internet, source: https://gist.github.com/johnny12150/3474bb2ed7467d6ac099f5da5db39093
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

// Month name array
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "December"};

// Arrow key bindings
const int KEY_UP = 'A';
const int KEY_DOWN = 'B';
const int KEY_RIGHT = 'C';
const int KEY_LEFT = 'D';

Calendar::Calendar(std::string events_path)
{
  // sets locale to support all unicode characters
  setlocale(LC_ALL, "");

  // read all events stored on disk
  File::readEvents(events, events_path);

  // exits the loop when changed to true
  bool quit = false;

  while (!quit)
  {
    // program rerender occours everytime a key is pressed
    // which saves some resources but allows near smooth scene transition
    updateDisplay();

    // input capture function
    int input = getch();

    // based on that captured input program selects the respective option
    switch (input)
    {
    case 'a':
      setDisplayMode(MONTH_VIEW);
      break;
    case 'w':
      setDisplayMode(WEEK_VIEW);
      break;
    case 'd':
      setDisplayMode(DAY_VIEW);
      break;
    case 's':
      setDisplayMode(SCHEDULE_VIEW);
      break;
    case 'c':
      setDisplayMode(CREATE_EVENT_VIEW);
      break;
    case 'e':
      setDisplayMode(EDIT_EVENT_VIEW);
      break;
    case 'x':
      setDisplayMode(DELETE_EVENT_VIEW);
      break;
    case 't':
      thisDay(today);
      break;
    case '\n':
      setDisplayMode(SELECTED_EVENT);
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

  File::writeEvents(events, events_path);
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

void Calendar::thisDay(Date &date)
{
  Date today;

  date.setDay(today.getDay());
  date.setMonth(today.getMonth());
  date.setYear(today.getYear());
}

void Calendar::setDisplayMode(DisplayMode layout)
{
  previousDisplayMode = current_layout;
  current_layout = layout;
}

void Calendar::updateDisplay()
{
  std::system("clear");

  switch (current_layout)
  {
  case MONTH_VIEW:
    getMonthView(today);
    getHelpView();
    break;
  case WEEK_VIEW:
    getWeekView(today);
    getHelpView();
    break;
  case DAY_VIEW:
    getDayView(today, now);
    getHelpView();
    break;
  case SCHEDULE_VIEW:
    getScheduleView(today);
    getHelpView();
    break;
  case CREATE_EVENT_VIEW:
    createEventView(today);
    break;
  case EDIT_EVENT_VIEW:
    editEventView(today);
    break;
  case DELETE_EVENT_VIEW:
    deleteEventView(today);
    break;
  case SELECTED_EVENT:
    getSelectedEvent(today);
    getHelpView();
    break;
  default:
    getScheduleView(today);
    break;
  }
}

std::vector<Event> Calendar::getEvents(Date &date)
{
  return events;
}

bool Calendar::day_exists(std::vector<Event> &events, int &day, std::string &color)
{
  for (auto event : events)
  {
    if (event.getStartDate().getDay() == day)
    {
      color = Color::getTerminalColor(event.getColor());
      return true;
    }
  }

  return false;
}

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

  for (auto event : events)
  {
    if (event.getStartDate().getMonth() == first_day_of_the_month.getMonth())
      events_this_month.push_back(event);
  }

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

      std::string color = "\033[1;103m";
      bool isEventToday = Calendar::day_exists(events_this_month, day, color);
      if (!first_iteration && last_iteration && isEventToday && day != date.getDay())
      {
        std::cout << color << std::setw(3) << day << " "
                  << "\033[0m";
      }
      else if (!first_iteration && last_iteration && day == date.getDay())
      {
        std::cout << "\033[1;44m" << std::setw(3) << day << " "
                  << "\033[0m";
      }
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

  for (int i = 0; i < 7; i++)
  {
    std::list<Event> events_today;

    for (Event event : events)
    {
      if (event.getStartDate() == temp_date)
        events_today.push_back(event);
    }

    std::cout << temp_date.getWeekDay() << " " << std::setw(2) << temp_date.getDay() << " | ";

    if (events_today.empty())
    {
      std::cout << "no events for today" << std::endl;
    }
    else if (events_today.size() == 1)
    {
      std::cout << events_today.front().getName() << std::endl;
    }
    else
    {
      std::cout << events_today.front().getName() << " and " << (events_today.size() - 1) << " more..." << std::endl;
    }

    if (!temp_date.setDay(temp_date.getDay() + 1))
    {
      temp_date.setDay(1);
      temp_date.setMonth(temp_date.getMonth() + 1);
    }

    events_today.clear();
  }
}

void Calendar::getDayView(Date &date, Time &time)
{
  std::cout << date.getWeekDay() << " " << months[date.getMonth() + 1] << " " << date.getDay() << " " << date.getYear() << std::endl;
  
  Time temp_time(0, 0);
  Date temp_date = date;

  std::vector<Event> events_today;

  for (auto event : events)
    if (event.getStartDate() == date || event.getEndDate() == date)
      events_today.push_back(event);

  for (int i = 0; i < 24; i++)
  {
    std::cout << std::setw(2) << temp_time.getHour() << ":00 | ";

    bool event_found = false;

    for (auto event : events_today)
    {
      if (!(event.getStartTime() > temp_time) && event.getEndTime() > temp_time)
      {
        std::cout << event.getName() << std::endl;
        event_found = true;
      }
    }

    if (!event_found)
    {
      std::cout << "no events for now" << std::endl;
    }

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
  std::multimap<Date, Event> events_upcoming;

  for (Event event : events)
  {
    if (event.getStartDate() == date)
      events_today.push_back(event);

    if (event.getStartDate() > date)
      events_upcoming.insert({event.getStartDate(), event});
  }

  std::cout << std::left << date.getWeekDay() << " " << months[date.getMonth() - 1] << " " << std::setw(2) << date.getDay() << " | ";

  if (events_today.empty())
  {
    std::cout << "no events for today" << std::endl;
  }
  else if (events_today.size() == 1)
  {
    std::cout << events[0].getName() << std::endl;
  }
  else
  {
    std::cout << events[0].getName() << " and " << (events_today.size() - 1) << " more..." << std::endl;
  }

  int max_schedule_length = (events_upcoming.size() <= 6) ? events_upcoming.size() : 6;

  auto it = events_upcoming.begin();
  for (int i = 0; i < max_schedule_length; i++)
  {
    Event event = it->second;
    std::cout << event.getStartDate().getWeekDay() << " " << months[event.getStartDate().getMonth() - 1] << " " << std::setw(2) << event.getStartDate().getDay() << " | " << event.getName() << std::endl;

    ++it;
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

  setDisplayMode(MONTH_VIEW);
  updateDisplay();
}

void Calendar::editEventView(Date &date)
{
  std::cout << "Edit an existing event" << std::endl
            << std::endl;

  std::string str = "";
  Date today;
  Time now;
  Color color;
  Event event(str, today, now, today, now, color, str);

  std::string event_id;

  getSelectedEvent(date);

  std::cout << "Provide event id: ";
  std::getline(std::cin, event_id);

  try
  {
    events.erase(events.begin() + std::stoi(event_id) - 1);

    Form::createDialogBox(event);
    events.push_back(event);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what();
  }

  setDisplayMode(MONTH_VIEW);
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

    events.erase(events.begin() + event_id - 1);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what();
  }

  setDisplayMode(MONTH_VIEW);
  updateDisplay();
}

void Calendar::getSelectedEvent(Date &date)
{
  std::vector<Event> events_today;

  for (auto event : events)
    if (event.getStartDate() == date)
      events_today.push_back(event);

  int temp_id = 1;

  if (events_today.size())
    std::cout << "Events today: " << std::endl;
  else
    std::cout << "No events for today" << std::endl;

  for (auto event : events_today)
  {
    auto sDate = event.getStartDate();
    auto sTime = event.getStartTime();
    auto eDate = event.getEndDate();
    auto eTime = event.getEndTime();

    auto color = event.getColor();
    std::stringstream color_stream;
    color_stream << std::hex << (color.getRed() << 16 | color.getGreen() << 8 | color.getBlue());

    std::cout << Color::getTerminalColor(color) << temp_id << "\033[0m"
              << ") "
              << "Name: " << event.getName() << std::endl
              << "Starts: " << sDate.getMonth() << "/" << std::setfill('0') << std::setw(2) << sDate.getDay() << "/" << sDate.getYear() << " "
              << std::setw(2) << sTime.getHour() << ":" << std::setfill('0') << std::setw(2) << sTime.getMinute() << std::endl
              << "Ends: " << eDate.getMonth() << "/" << std::setfill('0') << std::setw(2) << eDate.getDay() << "/" << eDate.getYear() << " "
              << std::setw(2) << eTime.getHour() << ":" << std::setfill('0') << std::setw(2) << eTime.getMinute() << std::endl
              << "Color: #" << std::setw(6) << color_stream.str() << std::endl
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
            << "x - delete selected event  "
            << "t - today"
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