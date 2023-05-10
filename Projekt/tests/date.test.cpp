#include <gtest/gtest.h>
#include "../date.h"

TEST(Date, inits)
{
  int day = 16;
  int month = 5;
  int year = 2023;

  Date first_date;
  Date second_date(day, month, year);

  EXPECT_EQ(second_date.getDay(), day);
  EXPECT_EQ(second_date.getMonth(), month);
  EXPECT_EQ(second_date.getYear(), year);
}