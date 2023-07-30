//
//  Sprite.cpp
//  grumble
//
//  Created by Benjamin Wallis on 30/07/2023.
//

#include "Sprite.hpp"

namespace grumble {
  Sprite::Sprite(std::string name, Region region) :
    _name(name),
    _region(region) {
    
  }

  std::string Sprite::name() {
    return _name;
  }

  Region Sprite::region() {
    return _region;
  }
}
