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
  Date today;
  Time now;

public:
  Calendar();

  void updateDisplay();
  void nextDay();
  void previousDay();
  void nextWeek();
  void previousWeek();
  void setDisplayMode();
  

  void createEvent(Event &event);
  bool deleteEvent(Event &event);
  bool editEvent(Event &event);
  std::vector<Event> getEvents(Date &date);
  void getMonthView(Date &date);
  std::string getWeekView(Date &date);
  std::string getDayView(Date &date);
  std::string getScheduleView();
  void getHelpView();
};

#endif