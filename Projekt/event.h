#ifndef EVENT_H
#define EVENT_H

#include <iostream>

#include "date.h"
#include "time.h"
#include "color.h"

class Event
{
private:
  std::string name;
  Date date;
  Time time;
  Color color;
  std::string notes;

public:
  Event(
      std::string &name,
      Date &date,
      Time &time,
      Color &color,
      std::string &notes);

  std::string getName();
  Date getDate();
  Time getTime();
  Color getColor();
  std::string getNotes();

  void setName(std::string &name);
  void setDate(Date &date);
  void setTime(Time &time);
  void setColor(Color &color);
  void setNotes(std::string &notes);

  bool operator<(Event &other);
  bool operator>(Event &other);
  bool operator==(Event &other);
};

#endif