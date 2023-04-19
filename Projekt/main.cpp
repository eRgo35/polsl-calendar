#include <iostream>
#include <ctime>
#include <ncurses.h>

std::string month_array[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
std::string day_array[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

std::string get_month(int &mon)
{
  if (mon < 0 || mon > 11)
    return "Month";
  return month_array[mon];
}

std::string get_day(int &day)
{
  if (day < 0 || day > 7)
    return "Day";
  if (day == 7)
    return day_array[day - 7];

  return day_array[day];
}

int main()
{
  // std::time_t t = std::time(0);
  // std::tm *now = std::localtime(&t);

  // std::cout
  //     << get_day(now->tm_wday)
  //     << ", "
  //     << get_month(now->tm_mon)
  //     << " "
  //     << now->tm_mday
  //     << "th "
  //     << (1900 + now->tm_year)
  //     << std::endl;

  // std::cout << std::endl;

  // int a = 0;
  // for (int i = 0; i < 5; i++)
  // {
  //   for (int j = 0; j < 7; j++)
  //   {
  //     std::cout << ++a << " ";
  //   }
  //   std::cout << std::endl;
  // }

  initscr();
  keypad(stdscr, TRUE);
  noecho();

  attron(A_BOLD);
  attron(COLOR_PAIR(1));
  printw("Hello World");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);

  int key;
  while ((key = getch()) != 'q')
  {
    switch (key)
    {
    case KEY_UP:
      printw("^");
      break;
    case KEY_DOWN:
      printw(".");
      break;
    case KEY_LEFT:
      printw("<");
      break;
    case KEY_RIGHT:
      printw(">");
      break;
    default:
      break;
    }
  }

  endwin();
  return 0;
}