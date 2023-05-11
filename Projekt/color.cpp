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

Color::Color(int red, int green, int blue)
{
  if (!Color::isValid(red, green, blue))
  {
    *this = Color();
  }
  else
  {
    this->red = red;
    this->green = green;
    this->blue = blue;
  }
}

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

bool Color::setRed(int red)
{
  if (!Color::isValid(red, green, blue))
    return false;

  this->red = red;
  return true;
}

bool Color::setGreen(int green)
{
  if (!Color::isValid(red, green, blue))
    return false;

  this->green = green;
  return true;
}

bool Color::setBlue(int blue)
{
  if (!Color::isValid(red, green, blue))
    return false;

  this->blue = blue;
  return true;
}

bool Color::isValid(int red, int green, int blue)
{
  if (red < 0 || red > 255)
    return false;

  if (green < 0 || green > 255)
    return false;

  if (blue < 0 || blue > 255)
    return false;

  return true;
}

bool Color::isValid()
{
  return isValid(red, green, blue);
}

std::string Color::toString()
{
  std::stringstream stream;
  stream << std::hex << red << std::hex << green << std::hex << blue;

  return ("#" + stream.str());
}

bool Color::operator==(Color &other)
{
  if (red != other.getRed())
    return false;

  if (green != other.getGreen())
    return false;

  if (blue != other.getBlue())
    return false;

  return true;
}