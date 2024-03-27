#pragma once

#include "../util/HandmadeMath.h"

#define EMPTY_INPUT                                                            \
  {                                                                            \
    false, false, { -1.0, -1.0 }                                               \
  }

namespace grumble {
struct FrameInput {
  bool shouldTerminate;
  bool handled;
  HMM_Vec2 touchPosition;

  bool isEmpty() const {
    return this->touchPosition.X == -1 && this->touchPosition.Y == -1;
  }
};
} // namespace grumble
