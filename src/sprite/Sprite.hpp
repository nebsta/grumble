//
//  Sprite.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "../core/Object.hpp"
#include "SpriteRegion.hpp"
#include <vector>

namespace grumble {

class Sprite : public Object {
public:
  typedef std::shared_ptr<Sprite> shared_ptr;
  typedef std::vector<shared_ptr> vector;
  typedef std::vector<shared_ptr>::iterator iterator;
  typedef vector::const_iterator const_iterator;

  Sprite(std::string name, std::string atlas, SpriteRegion region);

  const std::string name() const;
  const std::string atlas() const;
  const SpriteRegion region() const;

  const std::string toString() const override;

private:
  std::string _name;
  std::string _atlas;
  SpriteRegion _region;
};
} // namespace grumble
