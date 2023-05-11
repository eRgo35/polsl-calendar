#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "color.h"

Color::Color()
{
  red = 255;
  green = 255;
  blue = 255;
}

Color::Color(int red, int green, int blue) : red(red), green(green), blue(blue) {}

int Color::getRed()
{
  return red;
}

int Color::getGreen()
{
  return green;
}

int Color::getBlue()
{
  return blue;
}

bool Color::isValid()
{

}

std::string Color::toString()
{
  std::stringstream stream;
  stream << std::hex << red << std::hex << green << std::hex << blue;

  return ("#" + stream.str());
}