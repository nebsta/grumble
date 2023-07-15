//
//  SpriteManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "SpriteManager.hpp"

namespace grumble {
  SpriteManager::SpriteManager(SpriteHandler* spriteHandler) :
  _spriteHandler(spriteHandler)
  {
    _spriteHandler->loadAtlases();
  }

  SpriteManager::~SpriteManager() {
    
  }

  Sprite SpriteManager::loadSprite(const std::string &file, const std::string &spriteName) const {
    return SpriteEmpty;
  }
}
