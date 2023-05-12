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

  std::string getName() const;
  Date getDate() const;
  Time getTime() const;
  Color getColor() const;
  std::string getNotes() const;

  bool setName(std::string &name);
  bool setDate(Date &date);
  bool setTime(Time &time);
  bool setColor(Color &color);
  bool setNotes(std::string &notes);

  bool operator<(const Event &other) const;
  bool operator>(const Event &other) const;
  bool operator==(const Event &other) const;
  bool operator!=(const Event &other) const;
};

#endif