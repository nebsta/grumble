//
//  SpriteManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "SpriteManager.hpp"

namespace grumble {
  SpriteManager::SpriteManager(std::shared_ptr<FileManager> fileManager,
                               std::filesystem::path atlasPath) :
  _fileManager(fileManager),
  _atlasPath(atlasPath)
  {
    
  }

  SpriteManager::~SpriteManager() {
    
  }

  void SpriteManager::setup() {
    logInfo("Setting up SpriteManager");
    
    logInfo("Successfully set up SpriteManager");
  }

  std::shared_ptr<Sprite> SpriteManager::getSprite(std::string name, std::string atlas) {
    return nullptr;
  }

  LogCategory SpriteManager::logCategory() {
    return LogCategory::rendering;
  }

  std::filesystem::path SpriteManager::buildAtlasPath(std::filesystem::path filename) {
    return _atlasPath / filename;
  }
}
