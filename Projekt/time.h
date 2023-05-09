#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
private:
  int hour;
  int minute;

public:
  Time(int hour, int minute);

  int getHour();
  int getMinute();

  void setHour(int hour);
  void setMinute(int minute);

  bool isValid();
  std::string toString();

  bool operator>(Time &other);
  bool operator<(Time &other);
  bool operator==(Time &other);
};

#endif