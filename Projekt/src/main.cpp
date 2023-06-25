#include <iostream>
#include <gtest/gtest.h>

#include "../include/arguments.h"
#include "../include/event.h"
#include "../include/calendar.h"

int main(int argc, char *argv[])
{
  int app_mode = handle_arguments(argc, argv);
  std::string events_path = "events.txt";

  // invalid arguments error
  if (app_mode > 3)
    return 1;
  
  // custom events path
  if (app_mode == 3)
  {
    try {
      events_path = argv[2];
    }
    catch(std::exception e)
    {
      std::cerr << e.what();
      events_path = "events.txt";
    }
  }

  // --version // prints current version
  if (app_mode == 2)
    return 0;

  // --test-mode // library used - gtest
  if (app_mode == 1)
  {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

  Calendar calendar(events_path);

  return 0;
}