#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <ncurses.h>

#include "../include/date.h"

Date::Date()
{
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);

  day = tm->tm_mday;
  month = tm->tm_mon + 1;
  year = tm->tm_year + 1900;
  weekday = tm->tm_wday;

  int delta = weekday ? weekday - 1 : 7 - 1;
  week_number = (tm->tm_yday + 7 - delta) / 7;
}

Date::Date(int day, int month, int year)
{
  if (!Date::isValid(day, month, year))
  {
    *this = Date();
  }
  else
  {
    this->day = day;
    this->month = month;
    this->year = year;

    struct tm time_in = {
        .tm_mday = day,
        .tm_mon = month - 1,
        .tm_year = year - 1900,
    };

    time_t time_temp = mktime(&time_in);

    weekday = localtime(&time_temp)->tm_wday;
    int delta = weekday ? weekday - 1 : 7 - 1;
    week_number = (localtime(&time_temp)->tm_yday + 7 - delta) / 7;
  }
}

int Date::getDay() const
{
  return day;
}

int Date::getMonth() const
{
  return month;
}

int Date::getYear() const
{
  return year;
}

std::string Date::getWeekDay()
{
  const std::string day[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  return day[weekday];
}

int Date::getWeekNumber() const
{
  return week_number;
}

bool Date::setDay(int day)
{
  if (!Date::isValid(day, month, year))
    return false;

  this->day = day;
  return true;
}

bool Date::setMonth(int month)
{
  if (!Date::isValid(day, month, year))
    return false;

  this->month = month;
  return true;
}

bool Date::setYear(int year)
{
  if (!Date::isValid(day, month, year))
    return false;

  this->year = year;
  return true;
}

bool Date::isLeapYear(int year)
{
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    return true;

  return false;
}

bool Date::isValid(int day, int month, int year)
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

bool Date::isValid()
{
  return isValid(day, month, year);
}

std::string Date::toString()
{
  return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
}

bool Date::operator>(const Date &other) const
{
  if (year > other.getYear())
    return true;

  if (month > other.getMonth())
    return true;

  if (day > other.getDay())
    return true;

  return false;
}

bool Date::operator<(const Date &other) const
{
  if (year < other.getYear())
    return true;

  if (month < other.getMonth())
    return true;

  if (day < other.getDay())
    return true;

  return false;
}

bool Date::operator==(const Date &other) const
{
  if (year != other.getYear())
    return false;

  if (month != other.getMonth())
    return false;

  if (day != other.getDay())
    return false;

  return true;
}

bool Date::operator!=(const Date &other) const
{
  return !(*this == other);
}