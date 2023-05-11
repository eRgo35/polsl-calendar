#include "calendar.h"
#include "date.cpp"
#include "time.cpp"
#include "color.cpp"

#include <ncurses.h>

void Calendar::updateDisplay()
{
  clear();
  printw("Calendar view\n");
  refresh();
}