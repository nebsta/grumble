#pragma once

#include "HandmadeMath.h"

static float lerp(float start, float end, float t) {
  return start * (1.0 - t) + (end * t);
}

static HMM_Vec2 lerp(HMM_Vec2 start, HMM_Vec2 end, float t) {
  float x = lerp(start.X, end.X, t);
  float y = lerp(start.Y, end.Y, t);
  return {x, y};
}
