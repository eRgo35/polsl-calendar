/**
 * @file arguments.h
 * @author Michał Czyż
 * @brief Header file responsible for handling of program arguments.
 * @version 1.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023 All Rights Reserved
 * 
 */

#ifndef ARGS_H
#define ARGS_H

/// @brief Handles all program arguments.
/// @param argc Program argument count.
/// @param argv Program argument array.
/// @param events_path A reference to the events_path variable which may be changed by custom args.
/// @return Returns an integer that the main function handles and prints respective results.
int handle_arguments(int argc, char *argv[], std::string &events_path);

#endif