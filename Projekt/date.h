#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
  int day;
  int month;
  int year;

  bool isLeapYear(int year);

public:
  Date();
  Date(int day, int month, int year);

  int getDay();
  int getMonth();
  int getYear();

  bool setDay(int day);
  bool setMonth(int month);
  bool setYear(int year);

  bool isValid();
  std::string toString();

  bool operator>(Date &other);
  bool operator<(Date &other);
  bool operator==(Date &other);
};

#endif