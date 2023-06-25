/**
 * @file form.h
 * @author Michał Czyż
 * @brief Header file responsible for the form class definitions
 * @version 1.0
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023 All Rights Reserved
 * 
 */
#ifndef FORM_H
#define FORM_H

#include "event.h"

/// @brief Form class definition
class Form
{
public:
  /// @brief Static method that is responsible for a event form creator
  /// @param event An event object that will be overwriiten with new information
  /// @return Returns a bool if operation completed successfully
  static bool createDialogBox(Event &event);
};

#endif