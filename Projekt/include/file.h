/**
 * @file file.h
 * @author Michał Czyż
 * @brief Header file responsible for the file definitions
 * @version 1.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023 All Rights Reserved
 * 
 */
#ifndef FILE_H
#define FILE_H

#include "event.h"

#include <fstream>
#include <vector>

/// @brief File class definition
class File
{
public:
  /// @brief Static method that reads events from a file
  /// @param events A reference to the events vector
  /// @param events_path A path to the file with events
  /// @return Returns if operation completed successfully
  static bool readEvents(std::vector<Event> &events, std::string events_path);
  
  /// @brief Static method that writes events to a file
  /// @param events A reference to the events vector
  /// @param events_path A path to the file with events
  /// @return Returns if operation completed successfully
  static bool writeEvents(std::vector<Event> &events, std::string events_path);
};

#endif