/**
 * @file time.h
 * @author Michał Czyż
 * @brief Header file responsible for the time object definitions
 * @version 1.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023 All Rights Reserved
 * 
 */
#ifndef TIME_H
#define TIME_H

#include <iostream>

/// @brief Time class definition
class Time
{
private:
  int hour;
  int minute;

  /// @brief Checks if provided time is valid
  /// @param hour 
  /// @param minute 
  /// @return Returns a boolean if time is correct
  static bool isValid(int hour, int minute);
  
  /// @brief Checks if a current object holds correct values
  /// @return Returns a boolean if time is correct
  bool isValid();

public:
  /// @brief Default contructor
  Time();

  /// @brief Time contructor that allows setting custom time
  /// @param hour 
  /// @param minute 
  Time(int hour, int minute);

  /// @brief Hour getter
  /// @return Returns hour integer 0-23
  int getHour() const;
  
  /// @brief Minute getter
  /// @return Returns minute integer 0-59
  int getMinute() const;

  /// @brief Hour setter
  /// @param hour New hour to set
  /// @return Returns true if operation finished successfully
  bool setHour(int hour);

  /// @brief Minute setter
  /// @param minute New minute to set
  /// @return Returns true if operation finished successfully
  bool setMinute(int minute);

  /// @brief Converts time to string into hh:mm format
  /// @return Returns formatted time string
  std::string toString();

  /// @brief Logical operator method for comparing times
  /// @param other Another time object
  /// @return Returns true if this object is later in time than provided one
  bool operator>(const Time &other) const;
  
  /// @brief Logical operator method for comparing times
  /// @param other Another time object 
  /// @return Returns true if this object is earlier in time than provided one
  bool operator<(const Time &other) const;

  /// @brief Logical operator method for comparing times
  /// @param other Another time object 
  /// @return Returns true if this time is the same as provided
  bool operator==(const Time &other) const;
  
  /// @brief Logical operator method for comparing times
  /// @param other Another time object  
  /// @return Returns true if this time is different than provided
  bool operator!=(const Time &other) const;
};

#endif