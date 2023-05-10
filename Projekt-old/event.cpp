#include "event.h"

int Event::id_assigner = 0;

Event::Event(
    std::string event_name,
    event_time event_time,
    int event_color,
    std::string event_notes) : id(id_assigner++)
{
  name = event_name;
  time = event_time;
  color = event_color;
  notes = event_notes;
}

int Event::get_id()
{
  return id;
}

std::string Event::get_name()
{
  return name;
}

event_time Event::get_time()
{
  return time;
}

int Event::get_color()
{
  return color;
}

std::string Event::get_notes()
{
  return notes;
}

void Event::set_name(std::string &new_name)
{
  name = new_name;
}

void Event::set_time(event_time &new_time)
{
  time = new_time;
}

void Event::set_color(int &new_color)
{
  color = new_color;
}

void Event::set_notes(std::string &new_notes)
{
  notes = new_notes;
}