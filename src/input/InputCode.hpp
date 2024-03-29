#pragma once

#import <string>

namespace grumble {
enum InputCode {
  Unknown = 0,
  ArrowLeft = 1,
  ArrowUp = 2,
  ArrowRight = 3,
  ArrowDown = 4,
  MouseLeft = 5,
  MouseRight = 6,
  D = 7,
  E = 8
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
  case grumble::InputCode::MouseLeft:
    return "MouseLeft";
  case grumble::InputCode::MouseRight:
    return "MouseRight";
  case grumble::InputCode::D:
    return "D";
  case grumble::InputCode::E:
    return "E";
  case grumble::InputCode::Unknown:
    return "Unknown";
  }
}
} // namespace grumble
