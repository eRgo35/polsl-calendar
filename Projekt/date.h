#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
  int day;
  int month;
  int year;

public:
  Date(int day, int month, int year);

  int getDay();
  int getMonth();
  int getYear();

  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);

  bool isValid();
  std::string toString();

  bool operator>(Date &other);
  bool operator<(Date &other);
  bool operator==(Date &other);
};

#endif