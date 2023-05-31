#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
  int day;
  int month;
  int year;
  int weekday;
  int week_number;

  static bool isLeapYear(int year);
  static bool isValid(int day, int month, int year);
  bool isValid();

public:
  Date();
  Date(int day, int month, int year);

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  std::string getWeekDay();
  int getWeekDayNumber();
  int getWeekNumber() const;

  bool setDay(int day);
  bool setMonth(int month);
  bool setYear(int year);

  std::string toString();

  bool operator>(const Date &other) const;
  bool operator<(const Date &other) const;
  bool operator==(const Date &other) const;
  bool operator!=(const Date &other) const;
};

#endif