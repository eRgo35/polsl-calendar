#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"
#include "../include/form.h"

#include <locale.h>
#include <string>

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
      // calendar.editEvent();
      break;
    case 'x':
      // calendar.deleteEvent();
      break;
    case '\n':
      setDisplayMode(3);
      // TODO: Add View Details()
      break;
    case 'b':
      setDisplayMode(0);
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
  current_layout = layout;
}

void Calendar::updateDisplay()
{
  std::system("clear");

  switch (current_layout)
  {
  case 0:
    getMonthView(today);
    break;
  case 1:
    getWeekView(today);
    break;
  case 2:
    getDayView(today, now);
    break;
  case 3:
    getScheduleView(today);
    break;
  case 4:
    getEventView(today);
    break;
  default:
    getScheduleView(today);
    break;
  }

  getHelpView();
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
  std::string spacing = "";

  for (int i = 0; i < required_spaces; i++)
    spacing += " ";

  printf("%s%s %d\n", spacing.c_str(), months[date.getMonth() - 1], date.getYear());
  printf("%s\n", week_placeholder);
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
        printf("\033[1;44m%3d \033[0m", day);
      else
        printf("%3d ", day);

      day++;
    }
    printf("\n");
  }
}

void Calendar::getWeekView(Date &date)
{
  int header_length = std::string(months[date.getMonth() - 1]).length() + 12;
  int required_spaces = (27 - header_length) / 2;
  std::string spacing = "";

  for (int i = 0; i < required_spaces; i++)
    spacing += " ";
  printf("%sWeek %d - %s %d\n", spacing.c_str(), date.getWeekNumber(), months[date.getMonth() - 1], date.getYear());

  Date temp_date = date;

  std::vector<Event> events_today;

  for (Event event : events)
  {
    if (event.getStartDate() == date)
      events_today.push_back(event);
  }

  for (int i = 0; i < 7; i++)
  {
    printf("%s %2d | %s\n", temp_date.getWeekDay().c_str(), temp_date.getDay(), "no events for today");
    if (!temp_date.setDay(temp_date.getDay() + 1))
    {
      temp_date.setDay(1);
      temp_date.setMonth(temp_date.getMonth() + 1);
    }
  }
}

void Calendar::getDayView(Date &date, Time &time)
{
  printf("%s %s %2d %d\n", date.getWeekDay().c_str(), months[date.getMonth() + 1], date.getDay(), date.getYear());

  Time temp_time = time;
  Date temp_date = date;

  for (int i = 0; i < 7; i++)
  {
    printf("%2d:00 | %s\n", temp_time.getHour(), "no events for now");
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

  for (Event event : events)
  {
    if (event.getStartDate() == date)
      events_today.push_back(event);
  }

  if (events_today.empty())
  {
    printf("%s %s %d  | no events for today\n", date.getWeekDay().c_str(), months[date.getMonth() - 1], date.getDay());
  }
  else if (events_today.size() == 1)
  {
    printf("%s %s %d  | %s\n", date.getWeekDay().c_str(), months[date.getMonth() - 1], date.getDay(), events[0].getName());
  }
  else
  {
    printf("%s %s %d  | %s and %d more...\n", date.getWeekDay().c_str(), months[date.getMonth() - 1], date.getDay(), events[0].getName(), events_today.size() - 1);
  }

  int max_schedule_length = (events.size() <= 6) ? events.size() : 6;

  for (int i = 0; i < max_schedule_length; i++)
  {
    Event event = events[i];

    printf("%s %s %d  | %s\n", event.getStartDate().getWeekDay().c_str(), months[event.getStartDate().getMonth() - 1], event.getStartDate().getDay(), event.getName().c_str());
  }
}

void Calendar::getEventView(Date &date)
{
  printf("Create new event\n\n");

  std::string str = "";
  Date today;
  Time now;
  Color color;
  Event event(str, today, now, today, now, color, str);

  Form::createDialogBox(event);
  // while (std::cin >> choice);

  // char choice;
  // printf("Apply? [Y/n]\n");
    

  //   if (choice == 'Y' || choice == 'y' || choice == '\n')
  //     break;

}

void Calendar::getHelpView()
{
  // terminal colums get
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  const int COLS = w.ws_col;

  for (int i = 0; i < COLS; i++)
    printf("-");
  printf("\n");

  printf("→ - next day            ");
  printf("← - previous day         ");
  printf("↑ - next week              ");
  printf("↓ - previous week\n");
  printf("a - month view          ");
  printf("w - week view            ");
  printf("d - day view               ");
  printf("s - schedule view\n");
  printf("c - create a new event  ");
  printf("e - edit selected event  ");
  printf("x - delete selected event\n");
  printf("Enter - show details    ");
  printf("b - go back              ");
  printf("q - quit\n");
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