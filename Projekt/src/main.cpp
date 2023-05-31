#include <iostream>
#include <gtest/gtest.h>

#include "../include/arguments.h"
#include "../include/event.h"
#include "../include/calendar.h"

int main(int argc, char *argv[])
{
  int app_mode = handle_arguments(argc, argv);

  // invalid arguments error
  if (app_mode > 2)
    return 1;
  
  // --version // prints current version
  if (app_mode == 2)
    return 0;

  // --test-mode // library used - gtest
  if (app_mode == 1)
  {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

  // TODO Implement state saving

  Calendar calendar;

  return 0;
}