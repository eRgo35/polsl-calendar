#include <iostream>
#include "misc.h"
#include "colors.h"
#include <ctime>
#include <utility>

void br()
{
  std::cout << GREEN << "----------------------------" << CLEAR << std::endl;
}

void print_time(std::tm date)
{
  char buffer[100];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);

  std::cout << buffer << std::endl;
}