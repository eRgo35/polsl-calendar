#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

#include <ncurses.h>
#include <string>

Calendar::Calendar()
{
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
      // calendar.nextDay();
      break;
    case KEY_LEFT:
      // calendar.previousDay();
      break;
    case KEY_UP:
      // calendar.nextWeek();
      break;
    case KEY_DOWN:
      // calendar.previousWeek();
      break;
    case 'a':
      // calendar.setDisplayMode(Calendar::MONTH);
      break;
    case 'w':
      // calendar.setDisplayMode(Calendar::WEEK);
      break;
    case 'd':
      // calendar.setDisplayMode(Calendar::DAY);
      break;
    case 's':
      // calendar.setDisplayMode(Calendar::SCHEDULE);
      break;
    case 'c':
      // calendar.createEvent();
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

void Calendar::updateDisplay()
{
  clear();

  getMonthView(today);

  getHelpView();

  refresh();
}

void Calendar::getHelpView()
{
  for (int i = 0; i < COLS; i++)
    addch('-');

}

void Calendar::getMonthView(Date &date)
{
  printw("Month: %d\n", date.getMonth());
  printw("Year: %d\n", date.getYear());

  printw("%d\n", date.getWeekNumber());

  int day = 1;
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (day <= 31)
      {
        printw("%d ", day);
        day++;
      }
      else
      {
        printw(" ");
      }
    }
    printw("\n");
  }
}