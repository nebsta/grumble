#pragma once

#include "ReplayBehaviour.hpp"

namespace grumble {
struct SpriteAnimatorConfiguration {
  double frameDelay;
  bool playImmediately;
  ReplayBehaviour replayBehaviour;
};
} // namespace grumble
