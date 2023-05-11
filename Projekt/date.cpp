#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <string>

#include "date.h"

bool Date::isLeapYear(int year)
{
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    return true;

  return false;
}

Date::Date()
{
  std::time_t t = std::time(0);

  std::tm *now = std::localtime(&t);

  day = now->tm_mday;
  month = now->tm_mon + 1;
  year = now->tm_year + 1900;
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay()
{
  return day;
}

int Date::getMonth()
{
  return month;
}

int Date::getYear()
{
  return year;
}

bool Date::setDay(int day)
{
  if (day < 0 || day > 31)
    return false;

  // if ()

  this->day = day;
  return true;
}

bool Date::setMonth(int month)
{
  if (month > 0 || month <= 12)
  {
    this->month = month;
    return true;
  }
  return false;
}

bool Date::setYear(int year)
{
  if (year < 1900)
  {
    this->year = year;
    return true;
  }
  return false;
}

bool Date::isValid()
{
  if (year < 1900 || month < 1 || month > 12 || day < 1)
    return false;

  if (day > 31)
    return false;

  if (month == 2)
  {
    if (day > 29)
      return false;

    if (day == 29 && !Date::isLeapYear(year))
      return false;
  }

  if (month == 4 || month == 6 || month == 9 || month == 11)
    if (day == 31)
      return false;

  return true;
}

// static bool Date::isValid(int day, int month, int year)
// {
//   if (year < 1900 || month < 1 || month > 12 || day < 1)
//     return false;

//   if (day > 31)
//     return false;

//   if (month == 2)
//   {
//     if (day > 29)
//       return false;

//     if (day == 29 && !Date::isLeapYear(year))
//       return false;
//   }

//   if (month == 4 || month == 6 || month == 9 || month == 11)
//     if (day == 31)
//       return false;

//   return true;
// }

// std::string Date::toString()
// {
//   return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
// }

bool Date::operator>(Date &other)
{
  if (year > other.getYear())
    return true;

  if (month > other.getMonth())
    return true;

  if (day > other.getDay())
    return true;

  return false;
}

bool Date::operator<(Date &other)
{
  if (year < other.getYear())
    return true;

  if (month < other.getMonth())
    return true;

  if (day < other.getDay())
    return true;

  return false;
}

bool Date::operator==(Date &other)
{
  if (year != other.getYear())
    return false;

  if (month != other.getMonth())
    return false;

  if (day != other.getDay())
    return false;

  return true;
}