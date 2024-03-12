#pragma once

#import <string>

namespace grumble {
enum InputCode {
  Unknown = 0,
  ArrowLeft = 1,
  ArrowUp = 2,
  ArrowRight = 3,
  ArrowDown = 4
};

static std::string InputCode_to_string(InputCode code) {
  switch (code) {
  case grumble::InputCode::ArrowDown:
    return "Arrow-Down";
  case grumble::InputCode::ArrowUp:
    return "Arrow-Up";
  case grumble::InputCode::ArrowLeft:
    return "Arrow-Left";
  case grumble::InputCode::ArrowRight:
    return "Arrow-Right";
  case grumble::InputCode::Unknown:
    return "Unknown";
  }
}
} // namespace grumble
