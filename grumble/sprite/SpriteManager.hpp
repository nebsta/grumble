//
//  SpriteManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>
#include <glm/glm.hpp>
#include <map>

#include "Sprite.hpp"
#include "SpriteAtlas.hpp"

#include "../logging/Logger.hpp"
#include "../io/FileManager.hpp"

namespace grumble {
  typedef std::map<std::string, std::shared_ptr<SpriteAtlas>> AtlasMap;

  class SpriteManager: Object {
    
  public:
    SpriteManager(std::shared_ptr<FileManager> fileManager, std::filesystem::path atlasPath);
    ~SpriteManager();
    
    void setup();
    
    std::shared_ptr<Sprite> getSprite(std::string name, std::string atlas);
    std::vector<char> getAtlasData(std::string atlasName);
    
  protected:
    LogCategory logCategory() override;
    
  private:
    std::shared_ptr<FileManager> _fileManager;
    
    std::filesystem::path _atlasPath;
    
    AtlasMap _allAtlases;
    
    std::filesystem::path buildAtlasPath(std::filesystem::path atlasName);
  };
}
