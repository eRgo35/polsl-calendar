#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
  int day;
  int month;
  int year;

  static bool isLeapYear(int year);
  static bool isValid(int day, int month, int year);
  bool isValid();

public:
  Date();
  Date(int day, int month, int year);

  int getDay();
  int getMonth();
  int getYear();

  bool setDay(int day);
  bool setMonth(int month);
  bool setYear(int year);

  std::string toString();

  bool operator>(Date &other);
  bool operator<(Date &other);
  bool operator==(Date &other);
};

#endif