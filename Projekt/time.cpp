#include <iostream>
#include <string>
#include <ctime>

#include "time.h"

Time::Time()
{
  std::time_t t = std::time(0);

  std::tm *now = std::localtime(&t);

  hour = now->tm_hour;
  minute = now->tm_min;
}

Time::Time(int hour, int minute) : hour(hour), minute(minute) {}

int Time::getHour()
{
  return hour;
}

int Time::getMinute()
{
  return minute;
}

void Time::setHour(int hour)
{
  this->hour = hour;
}

void Time::setMinute(int minute)
{
  this->minute = minute;
}

bool Time::isValid()
{
  if (hour < 0 || hour > 23)
    return false;

  if (minute < 0 || minute > 59)
    return false;

  return true;
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