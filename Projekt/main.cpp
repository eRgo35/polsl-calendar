#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <gtest/gtest.h>

#include "event.h"
#include "calendar.cpp"

int main(int argc, char *argv[])
{
  bool test_mode = false;

  for (int i = 1; i < argc; i++)
  {
    if (std::strcmp(argv[i], "--test-mode") == 0)
    {
      test_mode = true;
    }
    else
    {
      std::cerr << "Error: Unknown argument " << argv[i] << std::endl;
      return 1;
    }
  }

  if (test_mode)
  {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  Calendar calendar;

  bool quit = false;
  while (!quit)
  {
    calendar.updateDisplay();

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

  return 0;
}