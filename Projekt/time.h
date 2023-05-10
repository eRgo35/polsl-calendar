#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
private:
  int hour;
  int minute;

public:
  Time();
  Time(int hour, int minute);

  int getHour();
  int getMinute();

  bool setHour(int hour);
  bool setMinute(int minute);

  bool isValid();
  std::string toString();

  bool operator>(Time &other);
  bool operator<(Time &other);
  bool operator==(Time &other);
};

#endif