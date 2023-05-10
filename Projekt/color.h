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
  Color();
  Color(int red, int green, int blue);

  int getRed();
  int getGreen();
  int getBlue();

  bool setRed(int red);
  bool setGreen(int green);
  bool setBlue(int blue);

  bool isValid();
  std::string toString();
};

#endif