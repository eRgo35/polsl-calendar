#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

#include "../include/color.h"

/// @brief for reference: https://en.wikipedia.org/wiki/ANSI_escape_code
/// @return Returns a vector of ansi extended color space
std::vector<std::pair<std::string, Color>> generateColors()
{
  int r, g, b = 0;
  // color range rgb steps
  std::vector<int> color_range = {0, 95, 135, 175, 215, 255};
  int r_range = 0, g_range = 0, b_range = 0;

  std::vector<std::pair<std::string, Color>> colors;
  // 16-232 is a extended color spectrum
  for (int i = 16; i < 232; i++)
  {
    // get ansi escape code sequence
    std::string code = "\033[48;5;" + std::to_string(i) + "m";

    // get color based on provided r, g, b values
    Color color(r, g, b);

    // push a color pair into an array
    colors.push_back({code, color});

    // increment all variables for the next color
    // works like incrementing numbers in mathematics 1...9 then 1 and 0 for 10
    b_range++;
    if (b_range >= color_range.size())
    {
      b_range = 0;
      g_range++;
      if (g_range >= color_range.size())
      {
        g_range = 0;
        r_range++;
        if (r_range >= color_range.size())
        {
          r_range = 0;
        }
      }
    }

    // set new color ranges from the array
    b = color_range[b_range];
    g = color_range[g_range];
    r = color_range[r_range];
  }

  // return the array
  return colors;
}

// variable that generates those colors
const std::vector<std::pair<std::string, Color>> colors = generateColors();

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

std::string Color::getTerminalColor(Color color)
{
  std::map<double, std::string> distance_array;

  for (auto term_color : colors)
  {
    double r = term_color.second.getRed() - color.getRed();
    double g = term_color.second.getGreen() - color.getGreen();
    double b = term_color.second.getBlue() - color.getBlue();

    double length = sqrt(r * r + g * g + b * b);

    distance_array.insert({length, term_color.first});
  }

  if (distance_array.empty())
    return "";

  return distance_array.begin()->second;
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