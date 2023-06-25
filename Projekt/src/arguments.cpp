#include <iostream>
#include <string>
#include <cstring>

#include "../include/arguments.h"

int handle_arguments(int argc, char *argv[], std::string &events_path)
{
  bool test_mode = false;

  for (int i = 1; i < argc; i++)
  {
    if (std::strcmp(argv[i], "--test-mode") == 0)
    {
      test_mode = true;
    }
    else if (std::strcmp(argv[i], "--version") == 0)
    {
      std::cout << "Calendar with event support. \nDeveloped by Michał Czyż. \nCopyright(c) 2023 All Rights Reserved." << std::endl;
      return 2;
    }
    else if (std::strcmp(argv[i], "--events-path") == 0)
    {
      if (i + 1 < argc)
      {
        events_path = argv[i + 1];
        i++;
      }
      else
      {
        std::cerr << "Error: Missing argument for --events-path" << std::endl;
        return 4;
      }

      return 3;
    }
    else
    {
      std::cerr << "Error: Unknown argument " << argv[i] << std::endl;
      return 4;
    }
  }

  return test_mode;
}