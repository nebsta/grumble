//
//  Sprite.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>

namespace grumble {
  typedef struct Region {
    float x, y, w, h;
  } Region;

  typedef struct Sprite {
    std::byte *data;
    Region region;
  } Sprite;

  const Sprite SpriteEmpty = { nullptr, {0, 0, 0, 0} };

  inline bool operator==(const Sprite& s1, const Sprite& s2)
  {
    if (s1.data == nullptr && s2.data == nullptr) {
      return true;
    } else if (s1.data == nullptr || s2.data == nullptr) {
      return false;
    }
    
    //TODO: fix comparison
    return true;
    //    return s1.texture.target == s2.texture.target;
  }

  inline bool isSpriteEmpty(Sprite sprite) {
    return sprite.data == nullptr;
  }
}
