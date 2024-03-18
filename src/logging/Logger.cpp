//
//  Logger.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Logger.hpp"
#include "../util/Time.hpp"
#include <iostream>

namespace grumble {

#pragma mark Public Methods

void Logger::log(std::string message, LogLevel level, LogCategory category) {
  if (level < Logger::activeLogLevel()) {
    return;
  }

  if (logCategoryDisabled(category)) {
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

#pragma mark Private Methods

std::string Logger::logLevelName(LogLevel level) {
  switch (level) {
  case LogLevel::debug:
    return "debug";
  case LogLevel::info:
    return "info";
  case LogLevel::warn:
    return "warn";
  case LogLevel::error:
    return "error";
  }
}

std::string Logger::logCategoryName(LogCategory category) {
  switch (category) {
  case LogCategory::none:
    return "";
  case LogCategory::core:
    return "core";
  case LogCategory::rendering:
    return "rendering";
  case LogCategory::ui:
    return "ui";
  case LogCategory::font:
    return "font";
  case LogCategory::io:
    return "io";
  case LogCategory::sprite:
    return "sprite";
  case LogCategory::input:
    return "input";
  }
}

bool Logger::logCategoryDisabled(LogCategory category) {
  auto pos = std::find(_disabledLogCategories.begin(),
                       _disabledLogCategories.end(), category);
  return pos != _disabledLogCategories.end();
}

void Logger::setActiveLogLevel(LogLevel level) { _activeLogLevel = level; }

void Logger::toggleLogCategory(LogCategory category) {
  auto pos = std::find(_disabledLogCategories.begin(),
                       _disabledLogCategories.end(), category);

  if (pos != _disabledLogCategories.end()) {
    _disabledLogCategories.erase(pos);
  } else {
    _disabledLogCategories.push_back(category);
  }
}

LogLevel Logger::activeLogLevel() { return _activeLogLevel; }
} // namespace grumble
