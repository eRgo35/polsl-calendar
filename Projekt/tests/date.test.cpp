#include <gtest/gtest.h>
#include <ctime>
#include "../include/date.h"

int day = 16;
int month = 5;
int year = 2023;

std::time_t date_t = std::time(0);
std::tm *date_now = std::localtime(&date_t);

int now_day = date_now->tm_mday;
int now_month = date_now->tm_mon + 1;
int now_year = date_now->tm_year + 1900;

TEST(Date, default_constructor)
{
  Date date;

  EXPECT_EQ(date.getDay(), now_day);
  EXPECT_EQ(date.getMonth(), now_month);
  EXPECT_EQ(date.getYear(), now_year);
}

TEST(Date, constructor_with_parameters)
{
  Date date(day, month, year);

  EXPECT_EQ(date.getDay(), day);
  EXPECT_EQ(date.getMonth(), month);
  EXPECT_EQ(date.getYear(), year);
}

TEST(Date, getters)
{
  Date date(day, month, year);

  EXPECT_EQ(date.getDay(), day);
  EXPECT_EQ(date.getMonth(), month);
  EXPECT_EQ(date.getYear(), year);
}

TEST(Date, setters)
{
  Date date;

  date.setDay(day);
  date.setMonth(month);
  date.setYear(year);

  EXPECT_EQ(date.getDay(), day);
  EXPECT_EQ(date.getMonth(), month);
  EXPECT_EQ(date.getYear(), year);
}

TEST(Date, day_isValid)
{
  Date today;

  Date first_oob_day(34, 1, 1970);
  Date second_oob_day(31, 4, 1970);
  Date third_oob_day(29, 2, 1999);
  Date fourth_oob_day(0, 1, 1970);
  Date fifth_oob_day(-1, 1, 1970);

  EXPECT_TRUE((first_oob_day == today));
  EXPECT_TRUE((second_oob_day == today));
  EXPECT_TRUE((third_oob_day == today));
  EXPECT_TRUE((fourth_oob_day == today));
  EXPECT_TRUE((fifth_oob_day == today));
}

TEST(Date, month_isValid)
{
  Date today;

  Date first_oob_month(1, -1, 1970);
  Date second_oob_month(1, 0, 1970);
  Date third_oob_month(1, 13, 1999);

  EXPECT_TRUE((first_oob_month == today));
  EXPECT_TRUE((second_oob_month == today));
  EXPECT_TRUE((third_oob_month == today));
}

TEST(Date, year_isValid)
{
  Date today;

  Date first_oob_year(1, 1, 1899);
  Date second_oob_year(1, 1, 0);
  Date third_oob_year(1, 1, -1);

  EXPECT_TRUE((first_oob_year == today));
  EXPECT_TRUE((second_oob_year == today));
  EXPECT_TRUE((third_oob_year == today));
}

TEST(Date, leap_years)
{
  Date today;

  Date leap(29, 2, 1900);
  Date leap2(29, 2, 2000);
  Date leap3(29, 2, 2020);

  EXPECT_TRUE((leap == today));
  EXPECT_FALSE((leap2 == today));
  EXPECT_FALSE((leap3 == today));
}

TEST(Date, toString)
{
  Date date(1, 1, 1970);

  EXPECT_EQ(date.toString(), "1970-1-1");
}

TEST(Date, operators)
{
  Date date1(day, month, year);
  Date date2(day, month, year);
  Date date3(day - 1, month, year);
  Date date4(day + 1, month, year);

  EXPECT_TRUE((date1 == date2));
  EXPECT_TRUE((date1 != date3));
  EXPECT_TRUE((date1 < date4));
  EXPECT_TRUE((date1 > date3));
}