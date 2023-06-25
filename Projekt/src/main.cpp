#include <iostream>
#include <gtest/gtest.h>

#include "../include/arguments.h"
#include "../include/event.h"
#include "../include/calendar.h"

int main(int argc, char *argv[])
{
  // default events file path
  std::string events_path = "events.txt";
  
  // handled arguments function returns an app_mode which prints respective information or changes specific modes
  int app_mode = handle_arguments(argc, argv, events_path);

  // invalid arguments error
  if (app_mode > 3)
    return 1;

  // --events-path // check if events_path is correct
  // if (app_mode == 3)
  // {
  //   std::cout << "Events path: " << events_path << std::endl;
  //   return 0;
  // }

  // --version // prints current version or
  // --help // prints version and available commands
  if (app_mode == 2)
    return 0;

  // --test-mode // library used - gtest
  if (app_mode == 1)
  {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

  // initialize a calendar from provided file
  Calendar calendar(events_path);

  // end a program when the calendar exits
  return 0;
}