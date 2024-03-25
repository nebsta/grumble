#pragma once

#include <fmt/format.h>
#include <string>

namespace grumble {
struct CameraRange {
  double left, top, bottom, right;

  std::string toString() const {
    return fmt::format("left: {}, top: {}, bottom: {}, right: {}", left, top,
                       bottom, right);
  }
};
} // namespace grumble
