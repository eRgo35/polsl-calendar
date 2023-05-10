#include <gtest/gtest.h>
#include "../event.h"

TEST(Event, initialization)
{
  event_time time;
  time.begin = 1;
  time.end = 2;

  Event event("Birthday", time, 123, "");

  EXPECT_EQ(123, event.get_color());
}