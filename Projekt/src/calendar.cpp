#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

#include <ncurses.h>

void Calendar::updateDisplay()
{
  clear();
  printw("Calendar view\n");
  refresh();
}