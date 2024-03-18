//
//  Logger.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "LogCategory.hpp"
#include "LogLevel.hpp"
#include <fmt/core.h>
#include <string>
#include <vector>

namespace grumble {
class Logger {
public:
  static void log(std::string message, LogLevel level, LogCategory category);

  template <typename... T>
  static void debug(const std::string message, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::debug,
                LogCategory::none);
  }

  template <typename... T> static void info(std::string message, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::info,
                LogCategory::none);
  }

  template <typename... T> static void warn(std::string message, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::warn,
                LogCategory::none);
  }

  template <typename... T> static void error(std::string message, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::error,
                LogCategory::none);
  }

  template <typename... T>
  static void debug(const std::string message, LogCategory category,
                    T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::debug,
                category);
  }

  template <typename... T>
  static void info(std::string message, LogCategory category, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::info,
                category);
  }

  template <typename... T>
  static void warn(std::string message, LogCategory category, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::warn,
                category);
  }

  template <typename... T>
  static void error(std::string message, LogCategory category, T &&...args) {
    Logger::log(fmt::format(fmt::runtime(message), args...), LogLevel::error,
                category);
  }

  static void setActiveLogLevel(LogLevel level);
  static void toggleLogCategory(LogCategory category);

  static bool logCategoryDisabled(LogCategory category);
  static LogLevel activeLogLevel();

  static std::string logCategoryName(LogCategory category);

private:
  static inline LogLevel _activeLogLevel = LogLevel::warn;
  static inline std::vector<LogCategory> _disabledLogCategories = {};

  static std::string logLevelName(LogLevel level);
};
} // namespace grumble
