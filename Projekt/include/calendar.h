/**
 * @file calendar.h
 * @author Michał Czyż
 * @brief Header file responsible for the main calendar class
 * @version 1.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023 All Rights Reserved
 * 
 */
#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <vector>

#include "event.h"
#include "date.h"

/// @brief DisplayMode enum, cleaner solution than passing integers
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

/// @brief The main calendar definition
class Calendar
{
private:
  std::vector<Event> events;
  Date today;
  Time now;
  DisplayMode current_layout = MONTH_VIEW;
  DisplayMode previousDisplayMode = MONTH_VIEW;

public:
  /// @brief Calendar constructor that initialized and holds entire calendar interface
  /// @param events_path Path to the events file containing all saved events
  Calendar(std::string events_path);

  /// @brief Rerenders the entire user interface
  void updateDisplay();

  /// @brief Changes current day to the next day
  /// @param date Provided date which should be incremented
  void nextDay(Date &date);
  
  /// @brief Changes current day to the previous day
  /// @param date Provided date which should be decremented
  void previousDay(Date &date);

  /// @brief Changes current day to the next week (moves by +7 days)
  /// @param date Provided date which should be changed
  void nextWeek(Date &date);

  /// @brief Changes current day to the previous week (moves by -7 days)
  /// @param date Provided date which should be changed
  void previousWeek(Date &date);

  /// @brief Resets the provided date to today
  /// @param date Provided date which should be changed
  void thisDay(Date &date);

  /// @brief Changes the active layout of a calendar
  /// @param layout A new layout that should be applied
  void setDisplayMode(DisplayMode layout);

  /// @brief Returns an array of all events in the calendar object
  /// @param date Unused
  /// @return Returns a vector of all availavle events
  std::vector<Event> getEvents(Date &date);
  
  /// @brief A static function that checks if a day with provided events exists (used in marking and coloring the day in layout view)
  /// @param events An array of events in the current month
  /// @param day Current day to be checked for
  /// @param color A color string that should be set the output to
  /// @return Returns a bool that can be used in checking if the day with the event exists
  static bool day_exists(std::vector<Event> &events, int &day, std::string &color);

  /// @brief Generates the month view inteface
  /// @param date Selected (active) date
  void getMonthView(Date &date);

  /// @brief Generates the week view interface
  /// @param date Selected (active) date
  void getWeekView(Date &date);

  /// @brief Generates the day view interface
  /// @param date Selected (active) date
  /// @param time Selected (active) time
  void getDayView(Date &date, Time &time);

  /// @brief Generates the schedule view interface
  /// @param date Selected (active) date
  void getScheduleView(Date &date);

  /// @brief Prints information about events that day and their details 
  /// @param date Selected (active) date
  void getSelectedEvent(Date &date);

  /// @brief Creates a new event in a calendar
  /// @param date Future Feature: Adds an event on selected earlier day
  void createEventView(Date &date);

  /// @brief Edits an existing event in a calendar
  /// @param date Shows a list of available events that day
  void editEventView(Date &date);

  /// @brief Deletes an existing event in a calendar
  /// @param date Shows a list of available events that day
  void deleteEventView(Date &date);

  /// @brief Generates a bottom help pane with keybinds
  void getHelpView();

  /// @brief Calculates how many days there are in a month
  /// @param date Provided date with a month
  /// @return Returns a number of days in a month
  int days_in_month(Date &date);
};

#endif