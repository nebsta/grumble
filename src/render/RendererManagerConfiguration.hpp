#pragma once

#include "Shape.hpp"
#include <vector>
namespace grumble {

struct RendererManagerConfiguration {
  float renderScale;
  std::vector<Shape> preloadedShapes;
};
} // namespace grumble
