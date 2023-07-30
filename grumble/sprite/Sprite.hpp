//
//  Sprite.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "../core/Object.hpp"

namespace grumble {
  typedef struct Region {
    float x, y, w, h;
  } Region;

  class Sprite: public Object {
  public:
    Sprite(std::string name, Region region);
    
    std::string name();
    Region region();
    
  private:
    std::string _name;
    Region _region;
  };
}
