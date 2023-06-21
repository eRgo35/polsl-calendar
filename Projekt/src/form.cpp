#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

#include "../include/form.h"
#include "../include/color.h"
#include "../include/date.h"
#include "../include/time.h"
#include "../include/event.h"

bool Form::createDialogBox(Event &event)
{
  std::string name;
  std::string start_date_time;
  std::string end_date_time;
  std::string hex_color;
  std::string notes;

  std::cout << "Name: ";
  std::getline(std::cin, name);

  std::cout << "Starts (MM/DD/YYYY HH:MM): ";
  std::getline(std::cin, start_date_time);

  std::cout << "Ends (MM/DD/YYYY HH:MM): ";
  std::getline(std::cin, end_date_time);

  std::cout << "Color (#______): ";
  std::getline(std::cin, hex_color);

  std::cout << "Notes: ";
  std::getline(std::cin, notes);

  std::string sMonth, sDay, sYear, sHour, sMinute;

  std::replace(start_date_time.begin(), start_date_time.end(), '/', ' ');
  std::replace(start_date_time.begin(), start_date_time.end(), ':', ' ');
  std::replace(start_date_time.begin(), start_date_time.end(), '-', ' ');

  std::stringstream start_date_time_stream(start_date_time);
  start_date_time_stream >> sMonth >> sDay >> sYear >> sHour >> sMinute;

  std::string eMonth, eDay, eYear, eHour, eMinute;

  std::replace(end_date_time.begin(), end_date_time.end(), '/', ' ');
  std::replace(end_date_time.begin(), end_date_time.end(), ':', ' ');
  std::replace(end_date_time.begin(), end_date_time.end(), '-', ' ');

  std::stringstream end_date_time_stream(end_date_time);
  end_date_time_stream >> eMonth >> eDay >> eYear >> eHour >> eMinute;

  try
  {
    event.setName(name);
    event.setNotes(notes);
  }
  catch (std::exception &e)
  {
  }

  try
  {
    // std::cout << "Month: " << sMonth << std::endl;
    // std::cout << "Day: " << sDay << std::endl;
    // std::cout << "Year: " << sYear << std::endl;
    // std::cout << "Hour: " << sHour << std::endl;
    // std::cout << "Minute: " << sMinute << std::endl;

    // std::cout << "Month: " << eMonth << std::endl;
    // std::cout << "Day: " << eDay << std::endl;
    // std::cout << "Year: " << eYear << std::endl;
    // std::cout << "Hour: " << eHour << std::endl;
    // std::cout << "Minute: " << eMinute << std::endl;

    Date start_date(std::stoi(sDay), std::stoi(sMonth), std::stoi(sYear));
    Time start_time(std::stoi(sHour), std::stoi(sMinute));
    Date end_date(std::stoi(eDay), std::stoi(eMonth), std::stoi(eYear));
    Time end_time(std::stoi(eHour), std::stoi(eMinute));

    event.setStartDate(start_date);
    event.setStartTime(start_time);
    event.setEndDate(end_date);
    event.setEndTime(end_time);
  }
  catch (std::exception &e)
  {
  }

  try
  {
    int red = strtol(hex_color.substr(1, 2).c_str(), nullptr, 16);
    int green = strtol(hex_color.substr(3, 2).c_str(), nullptr, 16);
    int blue = strtol(hex_color.substr(5, 2).c_str(), nullptr, 16);

    // std::cout << "Red: " << red << std::endl;
    // std::cout << "Green: " << green << std::endl;
    // std::cout << "Blue: " << blue << std::endl;

    Color color(red, green, blue);

    event.setColor(color);
  }
  catch (std::exception &e)
  {
  }

  return true;
}