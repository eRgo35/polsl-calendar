#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "../include/color.h"

std::string RED = "\033[1;31m";
std::string ORANGE = "\033[1;33m";
std::string GREEN = "\033[1;32m";
std::string BLUE = "\033[1;34m";
std::string WHITE = "\033[1;37m";
std::string CYAN = "\033[1;36m";
std::string MAGENTA = "\033[1;35m";
std::string YELLOW = "\033[1;93m";
std::string PURPLE = "\033[1;95m";
std::string GRAY = "\033[1;90m";
std::string CLEAR = "\033[0m";

std::string RED_BG = "\033[1;41m";
std::string ORANGE_BG = "\033[1;43m";
std::string GREEN_BG = "\033[1;42m";
std::string BLUE_BG = "\033[1;44m";
std::string WHITE_BG = "\033[1;47m";
std::string CYAN_BG = "\033[1;46m";
std::string MAGENTA_BG = "\033[1;45m";
std::string YELLOW_BG = "\033[1;103m";
std::string PURPLE_BG = "\033[1;105m";
std::string GRAY_BG = "\033[1;100m";

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

int Color::getRed() const
{
  return red;
}

int Color::getGreen() const
{
  return green;
}

int Color::getBlue() const
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

bool Color::operator==(const Color &other) const
{
  if (red != other.getRed())
    return false;

  if (green != other.getGreen())
    return false;

  if (blue != other.getBlue())
    return false;

  return true;
}

bool Color::operator!=(const Color &other) const
{
  return !(*this == other);
}