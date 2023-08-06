//
//  SpriteRegion.hpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#pragma once

#include <fmt/core.h>

namespace grumble {
  struct SpriteRegion {
    int x, y, w, h;
    
    std::string toString() const {
      return fmt::format("{}, {}, {}, {}", x, y, w, h);
    }
  };
}
