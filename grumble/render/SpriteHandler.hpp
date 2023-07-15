//
//  SpriteHandler.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>

#import "Sprite.hpp"

namespace grumble {
  class SpriteHandler {
    
  public:
    virtual ~SpriteHandler() { }
    
    virtual void loadAtlases() = 0;
    virtual Sprite loadSprite(const std::string& file, const std::string& spriteName) const = 0;
  };
}
