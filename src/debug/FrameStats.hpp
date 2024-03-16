#pragma once

namespace grumble {
struct FrameStats {
  float frameTimeMs;
  float updateTimeMs;
  float renderTimeMs;
  float frameLagMs;
  float frameDelayMs;
};
} // namespace grumble
