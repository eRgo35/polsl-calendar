#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <ctime>

struct event_time
{
  int begin;
  int end;
};

class Event
{
private:
  static int id_assigner;
  const int id;
  std::string name;
  event_time time;
  int color;
  std::string notes;

public:
  Event(
      std::string event_name,
      event_time event_time,
      int event_color,
      std::string event_notes);

  ~Event()
  {
  }

  int get_id();
  std::string get_name();
  event_time get_time();
  int get_color();
  std::string get_notes();
  void set_name(std::string &new_name);
  void set_time(event_time &new_time);
  void set_color(int &new_color);
  void set_notes(std::string &new_notes);
};

#endif