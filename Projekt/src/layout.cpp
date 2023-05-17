#include <ncurses.h>

  // initscr();
  // cbreak();
  // noecho();
  // keypad(stdscr, TRUE);

  // Calendar calendar;

  // bool quit = false;

  // while (!quit)
  // {
  //   calendar.updateDisplay();

  //   int input = getch();

  //   switch (input)
  //   {
  //   case KEY_RIGHT:
  //     // calendar.nextDay();
  //     break;
  //   case KEY_LEFT:
  //     // calendar.previousDay();
  //     break;
  //   case KEY_UP:
  //     // calendar.nextWeek();
  //     break;
  //   case KEY_DOWN:
  //     // calendar.previousWeek();
  //     break;
  //   case 'a':
  //     // calendar.setDisplayMode(Calendar::MONTH);
  //     break;
  //   case 'w':
  //     // calendar.setDisplayMode(Calendar::WEEK);
  //     break;
  //   case 'd':
  //     // calendar.setDisplayMode(Calendar::DAY);
  //     break;
  //   case 's':
  //     // calendar.setDisplayMode(Calendar::SCHEDULE);
  //     break;
  //   case 'c':
  //     // calendar.createEvent();
  //     break;
  //   case 'e':
  //     // calendar.editEvent();
  //     break;
  //   case 'x':
  //     // calendar.deleteEvent();
  //     break;
  //   case '\n':
  //     // calendar.showEventDetails();
  //     break;
  //   case KEY_BACKSPACE:
  //     // calendar.goBack();
  //     break;
  //   case 'q':
  //     quit = true;
  //     break;
  //   }
  // }