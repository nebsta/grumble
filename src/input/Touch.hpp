#pragma once

#include <glm/glm.hpp>

#include "../util/MathConstants.hpp"

namespace grumble {
struct Touch {
  int id;
  glm::vec2 location;
};

const Touch TouchEmpty = {-1, VECTOR_EMPTY};

} // namespace grumble
