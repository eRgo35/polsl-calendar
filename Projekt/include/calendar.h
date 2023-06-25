#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <vector>

#include "event.h"
#include "date.h"

// Instead of using integers,
// I use more readable enum
enum DisplayMode
{
  MONTH_VIEW,
  WEEK_VIEW,
  DAY_VIEW,
  SCHEDULE_VIEW,
  CREATE_EVENT_VIEW,
  EDIT_EVENT_VIEW,
  DELETE_EVENT_VIEW,
  SELECTED_EVENT
};

class Calendar
{
private:
  std::vector<Event> events;
  Date today;
  Time now;
  DisplayMode current_layout = MONTH_VIEW;
  DisplayMode previousDisplayMode = MONTH_VIEW;

public:
  Calendar(std::string events_path);

  void updateDisplay();
  void nextDay(Date &date);
  void previousDay(Date &date);
  void nextWeek(Date &date);
  void previousWeek(Date &date);
  void thisDay(Date &date);
  void setDisplayMode(DisplayMode layout);

  std::vector<Event> getEvents(Date &date);
  static bool day_exists(std::vector<Event> &events, int &day, std::string &color);

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