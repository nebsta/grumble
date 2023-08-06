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
    glm::vec2 topLeft, topRight, bottomLeft, bottomRight;
    
    std::string toString() const {
      return fmt::format("{}, {}, {}, {}",
                         glm::to_string(topLeft),
                         glm::to_string(topRight),
                         glm::to_string(bottomLeft),
                         glm::to_string(bottomRight));
    }
  };
}
