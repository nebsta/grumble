#pragma once

#include <fmt/core.h>
#include <glm/gtx/string_cast.hpp>

#include "../logging/Logger.hpp"

namespace grumble {
class Object {

public:
  Object(std::string_view id = "");
  ~Object();

  const std::string id() const;

  virtual const std::string toString() const;

protected:
  std::string _id;

  virtual LogCategory logCategory() const;

  template <typename... T>
  void logDebug(std::string message, T &&...args) const {
    Logger::debug(message, logCategory(), args...);
  }

  template <typename... T>
  void logInfo(std::string message, T &&...args) const {
    Logger::info(message, logCategory(), args...);
  }

  template <typename... T>
  void logWarn(std::string message, T &&...args) const {
    Logger::warn(message, logCategory(), args...);
  }

  template <typename... T>
  void logError(std::string message, T &&...args) const {
    Logger::error(message, logCategory(), args...);
  }
};
} // namespace grumble
