#include <gtest/gtest.h>
#include "../include/time.h"

int hour = 13;
int minute = 37;

TEST(Time, inits)
{
  Time first_time;
  Time second_time(hour, minute);
}

TEST(Time, getters)
{
  Time second_time(hour, minute);

  EXPECT_EQ(second_time.getHour(), hour);
  EXPECT_EQ(second_time.getMinute(), minute);
}

TEST(Time, setters)
{
  Time first_time;

  first_time.setHour(hour);
  first_time.setMinute(minute);

  EXPECT_EQ(first_time.getHour(), hour);
  EXPECT_EQ(first_time.getMinute(), minute);
}

TEST(Time, hour_isValid)
{
  Time now;

  Time first_oob_hour(-1, 10);
  Time second_oob_hour(24, 10);
  Time third_oob_hour(1024, 10);

  EXPECT_TRUE((first_oob_hour == now));
  EXPECT_TRUE((second_oob_hour == now));
  EXPECT_TRUE((third_oob_hour == now));
}

TEST(Time, minute_isValid)
{
  Time now;

  Time first_oob_minute(13, -1);
  Time second_oob_minute(13, 60);
  Time third_oob_minute(13, 2048);

  EXPECT_TRUE((first_oob_minute == now));
  EXPECT_TRUE((second_oob_minute == now));
  EXPECT_TRUE((third_oob_minute == now));
}

TEST(Time, toString)
{
  Time time(hour, minute);

  EXPECT_EQ(time.toString(), "13:37");
}

TEST(Time, operators)
{
  Time time1(hour, minute);
  Time time2(hour, minute);
  Time time3(hour - 1, minute);
  Time time4(hour + 1, minute);

  EXPECT_TRUE((time1 == time2));
  EXPECT_TRUE((time1 < time4));
  EXPECT_TRUE((time1 > time3));
}