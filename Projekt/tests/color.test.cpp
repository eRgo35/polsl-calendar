#include <gtest/gtest.h>
#include "../color.h"

TEST(Color, toString)
{
  Color color(255, 255, 255);
  EXPECT_EQ(color.toString(), "#ffffff");
}