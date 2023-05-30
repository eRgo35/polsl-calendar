#include "../include/event.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

#include <iostream>

Event::Event(
    std::string &name,
    Date &start_date,
    Time &start_time,
    Date &end_date,
    Time &end_time,
    Color &color,
    std::string &notes)
{
  Event::setName(name);

  this->start_date = start_date;
  this->start_time = start_time;
  this->end_date = end_date;
  this->end_time = end_time;
  this->color = color;
  this->notes = notes;
}

std::string Event::getName() const
{
  return name;
}

Date Event::getStartDate() const
{
  return start_date;
}

Time Event::getStartTime() const
{
  return start_time;
}

Date Event::getEndDate() const
{
  return end_date;
}

Time Event::getEndTime() const
{
  return end_time;
}

Color Event::getColor() const
{
  return color;
}

std::string Event::getNotes() const
{
  return notes;
}

int Event::getLength() const
{
  int years = end_date.getYear() - start_date.getYear();
  int months = end_date.getMonth() - start_date.getMonth();
  int days = end_date.getDay() - start_date.getDay();

  int length = 0;

  if (years > 0)
    length += years * 365;

  if (months > 0)
    length += months * 30;

  if (days > 0)
    length += days;

  return length;
}

bool Event::setName(std::string &name)
{
  if (name.empty() || name.size() > 255)
  {
    this->name = "Event";
    return false;
  }

  this->name = name;
  return true;
}

bool Event::setStartDate(Date &date)
{
  this->start_date = date;
  return true;
}

bool Event::setStartTime(Time &time)
{
  this->start_time = time;
  return true;
}

bool Event::setEndDate(Date &date)
{
  this->end_date = date;
  return true;
}

bool Event::setEndTime(Time &time)
{
  this->end_time = time;
  return true;
}

bool Event::setColor(Color &color)
{
  this->color = color;
  return true;
}

bool Event::setNotes(std::string &notes)
{
  this->notes = notes;
  return true;
}

bool Event::operator<(const Event &other) const
{
  if (start_date < other.getStartDate())
    return true;

  if (start_date == other.getStartDate() && start_time < other.getStartTime())
    return true;

  return false;
}

bool Event::operator>(const Event &other) const
{
  if (start_date > other.getStartDate())
    return true;

  if (start_date == other.getStartDate() && start_time > other.getStartTime())
    return true;

  return false;
}

bool Event::operator==(const Event &other) const
{
  if (name != other.getName())
    return false;

  if (start_date != other.getStartDate())
    return false;

  if (start_time != other.getStartTime())
    return false;

  if (color != other.getColor())
    return false;

  if (notes != other.getNotes())
    return false;

  return true;
}

bool Event::operator!=(const Event &other) const
{
  return !(*this == other);
}