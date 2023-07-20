//
//  Logger.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Logger.hpp"
#include <iomanip>

namespace grumble {

#pragma mark Public Methods

  void Logger::log(std::string message, LogLevel level, LogCategory category) {
    if (level >= Logger::activeLogLevel()) {
      return;
    }
    
    std::string levelName = Logger::logLevelName(level);
    
    std::cout << Time::nowString();
    
    std::cout << " [" << levelName << "] ";
    if (category != none) {
      std::string categoryName = Logger::logCategoryName(category);
      std::cout << "[" << categoryName << "] ";
    }
    std::cout << message << std::endl;
  }

  void Logger::debug(std::string message, LogCategory category) {
    Logger::log(message, LogLevel::debug, category);
  }

  void Logger::info(std::string message, LogCategory category) {
    Logger::log(message, LogLevel::info, category);
  }

  void Logger::warn(std::string message, LogCategory category) {
    Logger::log(message, LogLevel::warn, category);
  }

  void Logger::error(std::string message, LogCategory category) {
    Logger::log(message, LogLevel::error, category);
  }

#pragma mark Private Methods

  std::string Logger::logLevelName(LogLevel level) {
    switch (level) {
      case LogLevel::debug: return "debug";
      case LogLevel::info: return "info";
      case LogLevel::warn: return "warn";
      case LogLevel::error: return "error";
    }
  }

  std::string Logger::logCategoryName(LogCategory category) {
    switch (category) {
      case LogCategory::none: return "";
      case LogCategory::core: return "core";
      case LogCategory::rendering: return "rendering";
      case LogCategory::ui: return "ui";
    }
  }

  LogLevel Logger::activeLogLevel() {
#ifdef GRUMBLE_LOG_DEBUG
    return LogLevel::debug;
#elif GRUMBLE_LOG_INFO
    return LogLevel::info;
#elif GRUMBLE_LOG_WARN
    return LogLevel::warn;
#else // GRUMBLE_LOG_ERROR
    return LogLevel::error;
#endif
  }
}
