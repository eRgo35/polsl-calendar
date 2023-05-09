#ifndef COLOR_H
#define COLOR_H

#include <iostream>

struct Color
{
private:
  int red;
  int green;
  int blue;

public:
  Color(int red, int green, int blue);

  int getRed();
  int getGreen();
  int getBlue();

  bool isValid();
  std::string toString();
};

#endif