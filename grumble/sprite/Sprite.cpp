//
//  Sprite.cpp
//  grumble
//
//  Created by Benjamin Wallis on 30/07/2023.
//

#include "Sprite.hpp"

namespace grumble {
  Sprite::Sprite(std::string name, std::string atlas, SpriteRegion region) :
    Object(fmt::format("{}-{}", atlas, name)),
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

  const SpriteRegion Sprite::region() const {
    return _region;
  }

  const std::string Sprite::toString() const {
    return fmt::format("id: {}, name: {}, atlas: {}, region: {}", _id, _name, _atlas, _region.toString());
  }
}
