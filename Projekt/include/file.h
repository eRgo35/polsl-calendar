#ifndef FILE_H
#define FILE_H

#include "event.h"

#include <fstream>
#include <vector>

class File
{
public:
  static bool readEvents(std::vector<Event> &events, std::string events_path);
  static bool writeEvents(std::vector<Event> &events, std::string events_path);
};

#endif