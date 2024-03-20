//
//  SpriteRegion.hpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#pragma once

#include "../util/HandmadeMath.h"
#include "../util/MathUtils.hpp"
#include <fmt/core.h>
#include <glm/gtx/string_cast.hpp>

namespace grumble {
struct SpriteRegion {
  HMM_Vec2 tl, tr, bl, br;

  std::string toString() const {
    return fmt::format("{}, {}, {}, {}", HMM_Vec2_toString(tl),
                       HMM_Vec2_toString(tr), HMM_Vec2_toString(bl),
                       HMM_Vec2_toString(br));
  }
};
} // namespace grumble
