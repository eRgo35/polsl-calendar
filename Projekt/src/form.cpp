#include <iostream>
#include <string>
#include <sstream>

#include "../include/form.h"
#include "../include/color.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/event.h"

bool Form::createDialogBox(Event &event)
try {
  std::string name;
  std::string start_date_time;
  std::string end_date_time;
  std::string color_raw;
  std::string notes;

  std::cout << "Name: ";
  std::getline(std::cin, name);

  std::cout << "Starts (MM/DD/YYYY HH:MM): ";
  std::getline(std::cin, start_date_time);

  std::cout << "Ends (MM/DD/YYYY HH:MM): ";
  std::getline(std::cin, end_date_time);

  std::cout << "Color (#______): ";
  std::getline(std::cin, color_raw);

  std::cout << "Notes: ";
  std::getline(std::cin, notes);

  std::string sMonth, sDay, sYear, sHour, sMinute;
  std::stringstream start_date_time_stream(start_date_time);
  start_date_time_stream >> sMonth >> sDay >> sYear >> sHour >> sMinute;

  std::string eMonth, eDay, eYear, eHour, eMinute;
  std::stringstream end_date_time_stream(end_date_time);
  end_date_time_stream >> eMonth >> eDay >> eYear >> eHour >> eMinute;

  std::cout << sMonth << sDay << sYear << sHour << sMinute << std::endl;

  Date start_date(std::stoi(sDay), std::stoi(sMonth), std::stoi(sYear));
  Time start_time(std::stoi(sHour), std::stoi(sMinute));
  Date end_date(std::stoi(eDay), std::stoi(eMonth), std::stoi(eYear));
  Time end_time(std::stoi(eHour), std::stoi(eMinute));

  // if (color_raw.length() != 7 || color_raw[0] != '#')
  // {
  //   std::cout << "Invalid color string" << std::endl;
  //   return false;
  // }
  
  int color_int = std::stoi(color_raw.substr(1));

  int red = (color_int >> 16) & 0xFF;
  int green = (color_int >> 8) & 0xFF;
  int blue = color_int & 0xFF;

  Color color(red, green, blue);

  event.setName(name);
  event.setStartDate(start_date);
  event.setStartTime(start_time);
  event.setEndDate(end_date);
  event.setEndTime(end_time);
  event.setColor(color);
  event.setNotes(notes);

  return true;
} catch(std::exception& e)
{
  return false;
}