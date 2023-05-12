#include <gtest/gtest.h>
#include "../include/event.h"

#include <iostream>

TEST(Event, inits)
{
  std::string name = "Example Event";
  Date date;
  Time time;
  Color color;
  std::string notes = "Lorem ipsum dolor sit amet";

  Event example(name, date, time, color, notes);

  EXPECT_EQ(example.getName(), name);
}

TEST(Event, getters)
{

}

TEST(Event, setters)
{

}

TEST(Event, operators)
{

}