#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <vector>

#include "event.h"
#include "date.h"

class Calendar
{
private:
  std::vector<Event> events;

public:
  void updateDisplay();
  void nextDay();
  void previousDay();
  void nextWeek();
  void previousWeek();
  void setDisplayMode();
  

  void createEvent(const Event &event);
  bool deleteEvent(const Event &event);
  bool editEvent(const Event &event);
  std::vector<Event> getEvents(const Date &date) const;
  std::string getMonthView(const Date &date) const;
  std::string getWeekView(const Date &date) const;
  std::string getDayView(const Date &date) const;
  std::string getScheduleView() const;
};

#endif