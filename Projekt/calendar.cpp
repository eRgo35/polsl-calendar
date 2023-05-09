#include "calendar.h"
#include <ncurses.h>

void Calendar::updateDisplay()
{
  clear();
  printw("Calendar view");
  refresh();
}