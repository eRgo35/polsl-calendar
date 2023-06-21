#ifndef FILE_H
#define FILE_H

#include "event.h"

#include <fstream>
#include <vector>

class File
{
private:
  std::fstream file;

public:
  File(std::string path);
  ~File();

  bool readEvents(std::vector<Event> &events);
  bool writeEvents(std::vector<Event> &events);
};

#endif