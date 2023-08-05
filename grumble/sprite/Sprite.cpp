//
//  Sprite.cpp
//  grumble
//
//  Created by Benjamin Wallis on 30/07/2023.
//

#include "Sprite.hpp"

namespace grumble {
  Sprite::Sprite(std::string name, std::string atlas, Region region) :
    _name(name),
    _atlas(atlas),
    _region(region) {
    
  }

  const std::string Sprite::name() const {
    return _name;
  }

  const std::string Sprite::atlas() const {
    return _atlas;
  }

  const Region Sprite::region() const {
    return _region;
  }
}
