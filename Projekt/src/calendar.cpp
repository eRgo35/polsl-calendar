#include "../include/calendar.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

#include <ncurses.h>

Calendar::Calendar()
{
}

void Calendar::updateDisplay()
{
  clear();
  printw("Update!\n");
  
  for(int i = 0; i < COLS; i++)
    addch('-');

  refresh();
  getch();
}