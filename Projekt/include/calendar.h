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
  int current_layout = 0;

public:
  Calendar();

  void updateDisplay();
  void nextDay(Date &date);
  void previousDay(Date &date);
  void nextWeek();
  void previousWeek();
  void setDisplayMode(int layout);
  
  void createEvent(Event &event);
  bool deleteEvent(Event &event);
  bool editEvent(Event &event);

  std::vector<Event> getEvents(Date &date);

  void getMonthView(Date &date);
  void getWeekView(Date &date);
  void getDayView(Date &date);
  void getScheduleView(Date &date);
  
  void getEventView(Date &date);

  void getHelpView();
  
  int days_in_month(Date &date);
};

#endif