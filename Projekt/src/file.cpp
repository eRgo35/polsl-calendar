#include "../include/file.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool File::readEvents(std::vector<Event> &events)
{
  std::ifstream file("events.txt");

  if (!file.is_open())
    return false;

  std::string line;
  while (std::getline(file, line))
  { 
    std::vector<std::string> tokens;
    
    std::stringstream line_stream(line);

    while(line_stream.good())
    {
      std::string substring;
      getline(line_stream, substring, ';');
      tokens.push_back(substring);
    }

    Date start_date(std::stoi(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]));
    Time start_time(std::stoi(tokens[4]), std::stoi(tokens[5]));
    Date end_date(std::stoi(tokens[6]), std::stoi(tokens[7]), std::stoi(tokens[8]));
    Time end_time(std::stoi(tokens[9]), std::stoi(tokens[10]));
    Color color(std::stoi(tokens[11]), std::stoi(tokens[12]), std::stoi(tokens[13]));
    Event event(tokens[0], start_date, start_time, end_date, end_time, color, tokens[14]);

    events.push_back(event);
  }

  return true;
}

bool File::writeEvents(std::vector<Event> &events)
{
  std::ofstream file("events.txt");

  for (auto event : events)
  {
    std::string name = event.getName();
    int sDay = event.getStartDate().getDay();
    int sMonth = event.getStartDate().getMonth();
    int sYear = event.getStartDate().getYear();
    int sHour = event.getStartTime().getHour();
    int sMinute = event.getStartTime().getMinute();
    int eDay = event.getEndDate().getDay();
    int eMonth = event.getEndDate().getMonth();
    int eYear = event.getEndDate().getYear();
    int eHour = event.getEndTime().getHour();
    int eMinute = event.getEndTime().getMinute();
    int red = event.getColor().getRed();
    int green = event.getColor().getGreen();
    int blue = event.getColor().getBlue();
    std::string notes = event.getNotes();

    file << name << ";" << sDay << ";" << sMonth << ";" << sYear << ";" << sHour << ";" << sMinute << ";"
         << eDay << ";" << eMonth << ";" << eYear << ";" << eHour << ";" << eMinute << ";"
         << red << ";" << green << ";" << blue << ";" << notes << std::endl;
  }

  return true;
}
