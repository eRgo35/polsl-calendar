#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

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
    case 'l':
      nextDay();
      // KEYRIGHT
      break;
    case 'j':
      previousDay();
      // KEYLEFT
      break;
    case 'i':
      nextWeek();
      // KEYUP
      break;
    case 'k':
      previousWeek();
      // KEYDOWN
      break;
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
      // calendar.showEventDetails();
      break;
    case '=':
      // calendar.goBack();
      // BACKSPACE
      break;
    case 'q':
      quit = true;
      break;
    }
  }
}

void Calendar::nextDay()
{
  // TODO Impl cursor moving (dependant on the set DisplayMode())
}

void Calendar::previousDay()
{
  // TODO Impl cursor moving (dependant on the set DisplayMode())
}

void Calendar::nextWeek()
{
  // TODO Impl cursor moving (dependant on the set DisplayMode())
}

void Calendar::previousWeek()
{
  // TODO Impl cursor moving (dependant on the set DisplayMode())
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
    getDayView(today);
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

void Calendar::getMonthView(Date &date)
{
  const char *week_placeholder = "Sun Mon Tue Wed Thu Fri Sat";

  // I know that I know nothing about ncurses
  // So I center this on my own. Sorry :)

  int header_length = std::string(months[date.getMonth() - 1]).length() + 5;
  int required_spaces = (27 - header_length) / 2;
  std::string spacing = "";

  for (int i = 0; i < required_spaces; i++)
    spacing += " ";

  printf("%s%s %d\n", spacing.c_str(), months[date.getMonth() - 1], date.getYear());
  printf("%s\n", week_placeholder);
  // printw("%d\n", date.getWeekNumber());
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
  // attron(COLOR_PAIR(1));
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (!temp_date.setDay(day))
        day = 1;

      printf("%3d ", day);
      day++;
    }
    printf("\n");
  }
}

void Calendar::getWeekView(Date &date)
{
  printf("Week 10 - March 2023\n");
  printf("Sun  5 | \n");
  printf("Mon  6 | meeting\n");
  printf("Tue  7 | \n");
  printf("Wed  8 | lectures\n");
  printf("Thu  9 | exam\n");
  printf("Fri 10 | \n");
  printf("Sat 11 | \n");
}

void Calendar::getDayView(Date &date)
{
  printf(" 6 AM |             \n");
  printf(" 7 AM |             \n");
  printf(" 8 AM | :   exam   :\n");
  printf(" 9 AM | :          :\n");
  printf("10 AM | :..........:\n");
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
  printf("Backspace - go back      ");
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