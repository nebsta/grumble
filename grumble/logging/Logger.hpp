//
//  Logger.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <string>
#include <iostream>

#include "../util/Time.hpp"
#include "LogLevel.hpp"
#include "LogCategory.hpp"

namespace grumble {
  class Logger {
  public:
    static void log(std::string message, LogLevel level, LogCategory category);
    
    static void debug(std::string message, LogCategory category = none);
    static void info(std::string message, LogCategory category = none);
    static void warn(std::string message, LogCategory category = none);
    static void error(std::string message, LogCategory category = none);
    
  private:
    static std::string logLevelName(LogLevel level);
    static std::string logCategoryName(LogCategory category);
    
    static LogLevel activeLogLevel();
  };
}
