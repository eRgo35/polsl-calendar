#include "../include/file.h"

#include <iostream>
#include <fstream>

File::File(std::string path)
{
  file.open(path, std::ios::in);
}

File::~File()
{
  file.close();
}

bool File::readEvents(std::vector<Event> &events)
{
  if (!file.is_open())
    return false;

  while (file.eof())
  {
    std::string str = "";
    Date today;
    Time now;
    Color color;
    Event event(str, today, now, today, now, color, str);

    std::string event_name;

    file >> event_name;

    event.setName(event_name);
    
    events.push_back(event);

    // file.read(reinterpret_cast<char *>(&event), sizeof(event));
    // events.push_back(event);
  }

  return true;
}

bool File::writeEvents(std::vector<Event> &events)
{
  if (!file.is_open())
    return false;

  for (Event event : events)
  {
    file << event.getName();
    // file.write((char *)&event, sizeof(event));
  }

  return true;
}
