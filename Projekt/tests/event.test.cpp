#include <gtest/gtest.h>
#include "../include/event.h"

#include <iostream>

std::string name = "Example Event";
Date today;
Time now;
Color color;
std::string notes = "Lorem ipsum dolor sit amet";

TEST(Event, default_constructor)
{
  Event event(name, today, now, color, notes);

  EXPECT_EQ(event.getName(), name);
}

TEST(Event, getters)
{
  Event event(name, today, now, color, notes);

  EXPECT_EQ(event.getName(), name);
  EXPECT_EQ(event.getDate(), today);
  EXPECT_EQ(event.getTime(), now);
  EXPECT_EQ(event.getColor(), color);
  EXPECT_EQ(event.getNotes(), notes);
}

TEST(Event, setters)
{
  Event event(name, today, now, color, notes);

  std::string new_name = "Lorem ipsum";
  Date new_date(1, 1, 1970);
  Time new_time(13, 37);
  Color new_color(255, 127, 0);
  std::string new_notes("Important event notes");

  event.setName(new_name);
  event.setDate(new_date);
  event.setTime(new_time);
  event.setColor(new_color);
  event.setNotes(new_notes);

  EXPECT_EQ(event.getName(), new_name);
  EXPECT_EQ(event.getDate(), new_date);
  EXPECT_EQ(event.getTime(), new_time);
  EXPECT_EQ(event.getColor(), new_color);
  EXPECT_EQ(event.getNotes(), new_notes);
}

TEST(Event, operators)
{
  std::string custom_name = "Some other name";
  Date earlyd(1, 1, 1970);
  Time earlyt(0, 0);
  Date lated(31, 12, 2048);
  Time latet(23, 59);

  Event event1(name, today, now, color, notes);
  Event event2(name, today, now, color, notes);
  Event event3(custom_name, earlyd, now, color, notes);
  Event event4(name, lated, now, color, notes);
  Event event5(name, today, earlyt, color, notes);
  Event event6(name, today, latet, color, notes);

  EXPECT_TRUE((event1 == event2));
  EXPECT_TRUE((event1 != event3));
  EXPECT_TRUE((event1 < event4));
  EXPECT_TRUE((event1 > event3));
  EXPECT_TRUE((event1 < event6));
  EXPECT_TRUE((event1 > event5));
}