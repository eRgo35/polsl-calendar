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
  Date start_date;
  Time start_time;
  Date end_date;
  Time end_time;
  Color color;
  std::string notes;

public:
  Event(
      std::string &name,
      Date &start_date,
      Time &start_time,
      Date &end_date,
      Time &end_time,
      Color &color,
      std::string &notes);

  std::string getName() const;
  Date getStartDate() const;
  Time getStartTime() const;
  Date getEndDate() const;
  Time getEndTime() const;
  Color getColor() const;
  std::string getNotes() const;
  int getLength() const;

  bool setName(std::string &name);
  bool setStartDate(Date &date);
  bool setStartTime(Time &time);
  bool setEndDate(Date &date);
  bool setEndTime(Time &time);
  bool setColor(Color &color);
  bool setNotes(std::string &notes);

  bool operator<(const Event &other) const;
  bool operator>(const Event &other) const;
  bool operator==(const Event &other) const;
  bool operator!=(const Event &other) const;
};

#endif