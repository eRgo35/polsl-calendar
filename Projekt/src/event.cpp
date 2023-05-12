#include "../include/event.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/color.h"

#include <iostream>

Event::Event(std::string &name, Date &date, Time &time, Color &color, std::string &notes)
{
  Event::setName(name);
  
  this->date = date;
  this->time = time;
  this->color = color;
  this->notes = notes;
}

std::string Event::getName() const
{
  return name;
}

Date Event::getDate() const
{
  return date;
}

Time Event::getTime() const
{
  return time;
}

Color Event::getColor() const
{
  return color;
}

std::string Event::getNotes() const
{
  return notes;
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

bool Event::setDate(Date &date)
{
  this->date = date;
  return true;
}

bool Event::setTime(Time &time)
{
  this->time = time;
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
  if (date < other.getDate())
    return true;

  if (date == other.getDate() && time < other.getTime())
    return true;

  return false;
}

bool Event::operator>(const Event &other) const
{
  if (date > other.getDate())
    return true;
  
  if (date == other.getDate() && time > other.getTime())
    return true;

  return false;
}

bool Event::operator==(const Event &other) const
{
  if (name != other.getName())
    return false;

  if (date != other.getDate())
    return false;

  if (time != other.getTime())
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