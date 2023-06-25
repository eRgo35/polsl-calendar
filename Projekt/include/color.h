/**
 * @file color.h
 * @author Michał Czyż
 * @brief Header file responsible for the color object definitions
 * @version 1.0
 * @date 2023-06-25
 *
 * @copyright Copyright (c) 2023 All Rights Reserved
 *
 */
#ifndef COLOR_H
#define COLOR_H

#include <iostream>

/// @brief Color class definition
class Color
{
private:
  int red;
  int green;
  int blue;

  /// @brief Checks if a provided color triple is correct
  /// @param red Red intensity
  /// @param green Green intensity
  /// @param blue Blue intensity
  /// @return Returns a boolean if a color is valid
  static bool isValid(int red, int green, int blue);

  /// @brief Checks if a current object holds correct color values
  /// @return Returns a boolean if a color is valid
  bool isValid();

public:
  /// @brief Color constructor
  Color();

  /// @brief Color argument constructor
  /// @param red Red intensity
  /// @param green Green intensity
  /// @param blue Blue intensity
  Color(int red, int green, int blue);

  /// @brief Red getter
  /// @return Returns red intesity
  int getRed() const;

  /// @brief Green getter
  /// @return Returns green intensity
  int getGreen() const;

  /// @brief Blue getter
  /// @return Returns blue intensity
  int getBlue() const;

  /// @brief Red setter
  /// @param red New red intensity
  /// @return Returns if operation completed successfully
  bool setRed(int red);

  /// @brief Green setter
  /// @param green New green intensity
  /// @return Returns if operation completed successfully
  bool setGreen(int green);

  /// @brief Blue setter
  /// @param blue New blue intensity
  /// @return Returns if operation completed successfully
  bool setBlue(int blue);

  /// @brief Converts a color to string
  /// @return Returns a hexadecimal color code #000000
  std::string toString();

  /// @brief Converts RGB color spectrum to 256 ANSI terminal escape codes
  /// @param color Provided color object
  /// @return Returns ANSI terminal escape code sequence
  static std::string getTerminalColor(Color color);

  /// @brief Color logical operator method 
  /// @param other Another color
  /// @return Returns true if colors are the same
  bool operator==(const Color &other) const;

  /// @brief Color logical operator method
  /// @param other Another color 
  /// @return Returns true if colors are different
  bool operator!=(const Color &other) const;
};

#endif