#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color
{
private:
  int red;
  int green;
  int blue;

  static bool isValid(int red, int green, int blue);
  bool isValid();

public:
  Color();
  Color(int red, int green, int blue);

  int getRed();
  int getGreen();
  int getBlue();

  bool setRed(int red);
  bool setGreen(int green);
  bool setBlue(int blue);

  std::string toString();

  bool operator==(Color &other);
};

#endif