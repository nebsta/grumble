//
//  SpriteRegion.hpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#pragma once

#include <fmt/core.h>
#include <glm/gtx/string_cast.hpp>

namespace grumble {
struct SpriteRegion {
  glm::vec2 tl, tr, bl, br;

  std::string toString() const {
    return fmt::format("{}, {}, {}, {}", glm::to_string(tl), glm::to_string(tr),
                       glm::to_string(bl), glm::to_string(br));
  }
};
} // namespace grumble
