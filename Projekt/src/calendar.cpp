#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

#include <ncurses.h>
#include <locale.h>
#include <string>

Calendar::Calendar()
{
  setlocale(LC_ALL, "");
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);

  bool quit = false;

  while (!quit)
  {
    updateDisplay();

    int input = getch();

    switch (input)
    {
    case KEY_RIGHT:
      nextDay();
      break;
    case KEY_LEFT:
      previousDay();
      break;
    case KEY_UP:
      nextWeek();
      break;
    case KEY_DOWN:
      previousWeek();
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
    case KEY_BACKSPACE:
      // calendar.goBack();
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
  clear();

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

  refresh();
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
  const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "December"};
  const char *week_placeholder = "Sun Mon Tue Wed Thu Fri Sat";

  // I know that I know nothing about ncurses
  // So I center this on my own. Sorry :)

  int header_length = std::string(months[date.getMonth() - 1]).length() + 5;
  int required_spaces = (27 - header_length) / 2;
  std::string spacing = "";

  for (int i = 0; i < required_spaces; i++)
    spacing += " ";

  printw("%s%s %d\n", spacing.c_str(), months[date.getMonth() - 1], date.getYear());
  printw("%s\n", week_placeholder);
  // printw("%d\n", date.getWeekNumber());
  Date first_day_of_the_month(1, date.getMonth(), date.getYear());
  int first_day = first_day_of_the_month.getWeekDayNumber();
  // TODO Offset months by days & impl week number bar on the left
  Date last_month(1, date.getMonth() - 1, date.getYear());

  Date temp_date(date);

  int day = 1;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (!temp_date.setDay(day))
        day = 1;

      printw("%3d ", day);
      day++;
    }
    printw("\n");
  }
}

void Calendar::getWeekView(Date &date)
{
  printw("Week 10 - March 2023\n");
  printw("Sun  5 | \n");
  printw("Mon  6 | meeting\n");
  printw("Tue  7 | \n");
  printw("Wed  8 | lectures\n");
  printw("Thu  9 | exam\n");
  printw("Fri 10 | \n");
  printw("Sat 11 | \n");
}

void Calendar::getDayView(Date &date)
{
  printw(" 6 AM |             \n");
  printw(" 7 AM |             \n");
  printw(" 8 AM | :   exam   :\n");
  printw(" 9 AM | :          :\n");
  printw("10 AM | :..........:\n");
}

void Calendar::getScheduleView(Date &date)
{
  printw("Sun Mar 5  | no events for today\n");
  printw("Sun Mar 6  | event 1\n");
  printw("Sun Mar 10 | event 2\n");
  printw("Sun Mar 15 | event 3\n");
  printw("Sun Mar 21 | event 4\n");
}

void Calendar::getEventView(Date &date)
{
  printw("Create new event\n\n");
}

void Calendar::getHelpView()
{
  for (int i = 0; i < COLS; i++)
    addch('-');

  printw("→ - next day            ");
  printw("← - previous day         ");
  printw("↑ - next week              ");
  printw("↓ - previous week\n");
  printw("a - month view          ");
  printw("w - week view            ");
  printw("d - day view               ");
  printw("s - schedule view\n");
  printw("c - create a new event  ");
  printw("e - edit selected event  ");
  printw("x - delete selected event\n");
  printw("Enter - show details    ");
  printw("Backspace - go back      ");
  printw("q - quit\n");
}