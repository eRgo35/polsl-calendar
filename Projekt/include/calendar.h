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
  int previousDisplayMode = 0;

public:
  Calendar();

  void updateDisplay();
  void nextDay(Date &date);
  void previousDay(Date &date);
  void nextWeek(Date &date);
  void previousWeek(Date &date);
  void setDisplayMode(int layout);
  
  void createEvent(Event &event);
  bool deleteEvent(Event &event);
  bool editEvent(Event &event);

  std::vector<Event> getEvents(Date &date);

  void getMonthView(Date &date);
  void getWeekView(Date &date);
  void getDayView(Date &date, Time &time);
  void getScheduleView(Date &date);
  
  void createEventView(Date &date);
  void editEventView(Date &date);
  void deleteEventView(Date &date);

  void getSelectedEvent(Date &date);

  void getHelpView();
  
  int days_in_month(Date &date);
};

#endif