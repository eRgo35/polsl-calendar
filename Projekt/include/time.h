#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
private:
  int hour;
  int minute;

  static bool isValid(int hour, int minute);
  bool isValid();

public:
  Time();
  Time(int hour, int minute);

  int getHour() const;
  int getMinute() const;

  bool setHour(int hour);
  bool setMinute(int minute);

  std::string toString();

  bool operator>(const Time &other) const;
  bool operator<(const Time &other) const;
  bool operator==(const Time &other) const;
  bool operator!=(const Time &other) const;
};

#endif