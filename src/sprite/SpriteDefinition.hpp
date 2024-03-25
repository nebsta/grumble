//
//  Sprite.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "SpriteRegion.hpp"
#include <vector>

namespace grumble {
struct SpriteDefinition {
public:
  typedef std::vector<SpriteDefinition> vector;

  std::string_view name;
  std::string_view atlas;
  HMM_Vec2 size;
  SpriteRegion region;

  std::string toString() const {
    return fmt::format("name: {}, atlas: {}, region: {}, size: {}", name, atlas,
                       region.toString(), HMM_Vec2_toString(size));
  }

  bool isEmpty() const { return name.size() == 0; }
};
} // namespace grumble
