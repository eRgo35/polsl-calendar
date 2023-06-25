#include <iostream>
#include <gtest/gtest.h>

#include "../include/arguments.h"
#include "../include/event.h"
#include "../include/calendar.h"

int main(int argc, char *argv[])
{
  std::string events_path = "events.txt";
  int app_mode = handle_arguments(argc, argv, events_path);

  // invalid arguments error
  if (app_mode > 3)
    return 1;

  // if (app_mode == 3)
  // {
  //   std::cout << "Events path: " << events_path << std::endl;
  //   return 0;
  // }

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