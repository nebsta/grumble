//
//  Logger.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <fmt/core.h>
#include <iostream>
#include <string>
#include <vector>

#include "../util/Time.hpp"
#include "LogCategory.hpp"
#include "LogLevel.hpp"

namespace grumble {
class Logger {
public:
  static void log(std::string message, LogLevel level, LogCategory category);

  template <typename... T>
  static void debug(const std::string message,
                    LogCategory category = LogCategory::none, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::debug,
                category);
  }

  template <typename... T>
  static void info(std::string message,
                   LogCategory category = LogCategory::none, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::info,
                category);
  }

  template <typename... T>
  static void warn(std::string message,
                   LogCategory category = LogCategory::none, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::warn,
                category);
  }

  template <typename... T>
  static void error(std::string message,
                    LogCategory category = LogCategory::none, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::error,
                category);
  }

  static void setActiveLogLevel(LogLevel level);
  static void toggleLogCategory(LogCategory category);

  static bool logCategoryDisabled(LogCategory category);
  static LogLevel activeLogLevel();

private:
  static inline LogLevel _activeLogLevel = LogLevel::warn;
  static inline std::vector<LogCategory> _disabledLogCategories = {};

  static std::string logLevelName(LogLevel level);
  static std::string logCategoryName(LogCategory category);
};
} // namespace grumble
