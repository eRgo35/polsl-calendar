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

  int getRed() const;
  int getGreen() const;
  int getBlue() const;

  bool setRed(int red);
  bool setGreen(int green);
  bool setBlue(int blue);

  std::string toString();
  static std::string getTerminalColor(Color color);

  bool operator==(const Color &other) const;
  bool operator!=(const Color &other) const;
};

#endif