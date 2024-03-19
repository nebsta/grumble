//
//  Sprite.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "SpriteRegion.hpp"

namespace grumble {

struct SpriteDefinition {
  std::string_view name;
  std::string_view atlas;
  SpriteRegion region;

  std::string toString() const {
    return fmt::format("name: {}, atlas: {} region: {}", name, atlas,
                       region.toString());
  }
};
} // namespace grumble
