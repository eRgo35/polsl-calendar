#include <gtest/gtest.h>
#include "../include/color.h"

TEST(Color, inits)
{
  Color white;
  
  Color coral(255, 127, 80);
  Color sky_blue(135, 206, 235);
  Color lavender(230, 230, 250);
  Color forest_green(34, 139, 34);
  Color slate_gray(112, 128, 144);
}

TEST(Color, getters)
{
  Color coral(255, 127, 80);

  EXPECT_EQ(coral.getRed(), 255);
  EXPECT_EQ(coral.getGreen(), 127);
  EXPECT_EQ(coral.getBlue(), 80);
}

TEST(Color, setters)
{
  Color coral;

  coral.setRed(255);
  coral.setGreen(127);
  coral.setBlue(80);

  EXPECT_EQ(coral.getRed(), 255);
  EXPECT_EQ(coral.getGreen(), 127);
  EXPECT_EQ(coral.getBlue(), 80);
}

TEST(Color, isValid)
{
  Color white;

  Color minusRed(-10, 0, 0);
  Color minusGreen(0, -10, 0);
  Color minusBlue(0, 0, -10);

  Color nineBitRed(256, 0, 0);
  Color nineBitGreen(0, 256, 0);
  Color nineBitBlue(0, 0, 256);

  EXPECT_TRUE((minusRed == white));
  EXPECT_TRUE((minusGreen == white));
  EXPECT_TRUE((minusBlue == white));
  EXPECT_TRUE((nineBitRed == white));
  EXPECT_TRUE((nineBitGreen == white));
  EXPECT_TRUE((nineBitBlue == white));
}

TEST(Color, toString)
{
  Color color(255, 255, 255);
  EXPECT_EQ(color.toString(), "#ffffff");
}

TEST(Color, operators)
{
  Color coral(255, 127, 80);
  Color same_coral(255, 127, 80);
  Color sky_blue(135, 206, 235);

  EXPECT_TRUE((coral == same_coral));
  EXPECT_TRUE((coral != sky_blue));
  EXPECT_FALSE((coral == sky_blue));
}