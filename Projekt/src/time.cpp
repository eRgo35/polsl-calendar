#include <iostream>
#include <string>
#include <ctime>

#include "../include/time.h"

Time::Time()
{
  std::time_t t = std::time(0);

  std::tm *now = std::localtime(&t);

  hour = now->tm_hour;
  minute = now->tm_min;
}

Time::Time(int hour, int minute)
{
  if (!Time::isValid(hour, minute))
  {
    *this = Time();
  }
  else
  {
    this->hour = hour;
    this->minute = minute;
  }
}

int Time::getHour()
{
  return hour;
}

int Time::getMinute()
{
  return minute;
}

bool Time::setHour(int hour)
{
  if (!Time::isValid(hour, minute))
    return false;

  this->hour = hour;
  return true;
}

bool Time::setMinute(int minute)
{
  if (!Time::isValid(hour, minute))
    return false;

  this->minute = minute;
  return true;
}

bool Time::isValid(int hour, int minute)
{
  if (hour < 0 || hour > 23)
    return false;

  if (minute < 0 || minute > 59)
    return false;

  return true;
}

bool Time::isValid()
{
  return isValid(hour, minute);
}

std::string Time::toString()
{
  return std::to_string(hour) + ":" + std::to_string(minute);
}

bool Time::operator>(Time &other)
{
  if (hour > other.getHour())
    return true;

  if (minute > other.getMinute())
    return true;

  return false;
}

bool Time::operator<(Time &other)
{
  if (hour < other.getHour())
    return true;

  if (minute < other.getMinute())
    return true;

  return false;
}

bool Time::operator==(Time &other)
{
  if (hour != other.getHour())
    return false;

  if (minute != other.getMinute())
    return false;

  return true;
}