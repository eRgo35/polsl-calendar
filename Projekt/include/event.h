/**
 * @file event.h
 * @author Michał Czyż
 * @brief Header file responsible for the event object definitions
 * @version 1.0
 * @date 2023-06-25
 *
 * @copyright Copyright (c) 2023 All Rights Reserved
 *
 */
#ifndef EVENT_H
#define EVENT_H

#include <iostream>

#include "date.h"
#include "time.h"
#include "color.h"

/// @brief Event class definition
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
  /// @brief Event constructor
  /// @param name Name of the event
  /// @param start_date Date when the event starts
  /// @param start_time Time when the event starts
  /// @param end_date Date when the event ends
  /// @param end_time Time when the event ends
  /// @param color Desired color object of the event
  /// @param notes Additional notes regarding the event
  Event(
      std::string &name,
      Date &start_date,
      Time &start_time,
      Date &end_date,
      Time &end_time,
      Color &color,
      std::string &notes);

  /// @brief Name getter
  /// @return Returns the name of the event
  std::string getName() const;

  /// @brief Start Date getter
  /// @return Returns the date when the event starts
  Date getStartDate() const;

  /// @brief Start Time getter
  /// @return Returns the time when the event starts
  Time getStartTime() const;

  /// @brief End Date getter
  /// @return Returns the date when the event ends
  Date getEndDate() const;

  /// @brief End Time getter
  /// @return Returns the time when the event ends
  Time getEndTime() const;

  /// @brief Color getter
  /// @return Returns the color of the event
  Color getColor() const;

  /// @brief Notes getter
  /// @return Returns the notes associated with the event
  std::string getNotes() const;

  /// @brief Calculates the length of the event
  /// @return Returns the length of the event in days
  int getLength() const;

  /// @brief Sets the name of the event.
  /// @param name A reference to the new name to set.
  /// @return Returns true if the name was set successfully.
  bool setName(std::string &name);

  /// @brief Sets the start date of the event.
  /// @param date A reference to the new start date to set.
  /// @return Returns true if the start date was set successfully.
  bool setStartDate(Date &date);

  /// @brief Sets the start time of the event.
  /// @param time A reference to the new start time to set.
  /// @return Returns true if the start time was set successfully.
  bool setStartTime(Time &time);

  /// @brief Sets the end date of the event.
  /// @param date A reference to the new end date to set.
  /// @return Returns true if the end date was set successfully.
  bool setEndDate(Date &date);

  /// @brief Sets the end time of the event.
  /// @param time A reference to the new end time to set.
  /// @return Returns true if the end time was set successfully.
  bool setEndTime(Time &time);

  /// @brief Sets the color of the event.
  /// @param color A reference to the new color to set.
  /// @return Returns true if the color was set successfully.
  bool setColor(Color &color);

  /// @brief Sets the notes of the event.
  /// @param notes A reference to the new notes to set.
  /// @return Returns true if the notes were set successfully.
  bool setNotes(std::string &notes);

  /// @brief Less-than operator for comparing two Event objects.
  /// @param other Another Event object to compare.
  /// @return Returns true if this event is less than the provided event.
  bool operator<(const Event &other) const;

  /// @brief Greater-than operator for comparing two Event objects.
  /// @param other Another Event object to compare.
  /// @return Returns true if this event is greater than the provided event.
  bool operator>(const Event &other) const;

  /// @brief Equality operator for comparing two Event objects.
  /// @param other Another Event object to compare.
  /// @return Returns true if this event is equal to the provided event.
  bool operator==(const Event &other) const;

  /// @brief Inequality operator for comparing two Event objects.
  /// @param other Another Event object to compare.
  /// @return Returns true if this event is not equal to the provided event.
  bool operator!=(const Event &other) const;
};

#endif