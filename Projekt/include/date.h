/**
 * @file date.h
 * @author Michał Czyż
 * @brief Header file responsible for the date object definitions
 * @version 1.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023 All Rights Reserved
 * 
 */
#ifndef DATE_H
#define DATE_H

#include <iostream>

/// @brief Date class defninition
class Date

{
private:
  int day;
  int month;
  int year;
  int weekday;
  int week_number;

  /// @brief Checks if provided date is valid
  /// @param day 
  /// @param month 
  /// @param year 
  /// @return Returns a boolean if a date is correct
  static bool isValid(int day, int month, int year);
  
  /// @brief Checks if a current object holds correct values
  /// @return Returns a boolean if a date is correct
  bool isValid();

public:
  /// @brief Default constructor
  Date();

  /// @brief Date contructor that allows setting custom date
  /// @param day 
  /// @param month 
  /// @param year 
  Date(int day, int month, int year);

  /// @brief Day getter
  /// @return Returns object's day
  int getDay() const;

  /// @brief Month getter
  /// @return Returns object's month
  int getMonth() const;

  /// @brief Year getter
  /// @return Returns object's year
  int getYear() const;

  /// @brief Calculates the day of the week
  /// @return Returns the day of the week in string format 
  std::string getWeekDay();
  
  /// @brief Calculates the day of the week
  /// @return Returns the day of the week as a number from 0 to 6
  int getWeekDayNumber();
  
  /// @brief Calculates the number of week in a year
  /// @return Returns an integer between 1 and 52
  int getWeekNumber() const;

  /// @brief Day setter
  /// @param day New day value to set
  /// @return Returns if operation completed successfully
  bool setDay(int day);

  /// @brief Month setter
  /// @param month New month value to set
  /// @return Returns if operation completed successfully
  bool setMonth(int month);
  
  /// @brief Year setter
  /// @param year New year value to set
  /// @return Returns if operation completed successfully
  bool setYear(int year);

  /// @brief Converts this object into a string format
  /// @return Returns a date in a YYYY-MM-DD format
  std::string toString();

  /// @brief Checks if the provided year is a leap year
  /// @param year 
  /// @return Returns true if it is a leap year
  static bool isLeapYear(int year);

  /// @brief Logical operator method for comparing dates
  /// @param other Another date object
  /// @return Returns true if this object is later in time than provided one
  bool operator>(const Date &other) const;
  
  /// @brief Logical operator method for comparing dates
  /// @param other Another date object
  /// @return Returns true if this object is earlier in time than provided one
  bool operator<(const Date &other) const;
  
  /// @brief Logical operator method for comparing dates
  /// @param other Another date object
  /// @return Returns true if this date is the same as provided
  bool operator==(const Date &other) const;
  
  /// @brief Logical operator method for comparing dates
  /// @param other Another date object
  /// @return Returns true if this date is different than provided
  bool operator!=(const Date &other) const;
};

#endif