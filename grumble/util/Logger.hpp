//
//  Logger.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <string>
#include <sstream>
#include <iostream>

namespace grumble {
  class Logger {
      
  public:
    static void logMessage(std::string message);
    static void logMessage(std::string message, const char* vs...);
    static void logError(std::string message);
  };
}
