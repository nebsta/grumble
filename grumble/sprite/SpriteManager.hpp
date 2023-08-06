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
#include "SpriteManagerConfiguration.hpp"

#include "../logging/Logger.hpp"
#include "../io/FileManager.hpp"

namespace grumble {
  typedef std::map<std::string, std::shared_ptr<SpriteAtlas>> AtlasMap;
  typedef AtlasMap::const_iterator AtlasMapIterator;

  class SpriteManager: Object {
    
  public:
    SpriteManager(SpriteManagerConfiguration configuration,
                  std::shared_ptr<FileManager> fileManager);
    ~SpriteManager();
    
    void setup();
    
    std::shared_ptr<Sprite> getSprite(std::string name, std::string atlas);
    
    const std::vector<std::shared_ptr<SpriteAtlas>> allAtlases() const;
    
  protected:
    LogCategory logCategory() override;
    
  private:
    SpriteManagerConfiguration _configuration;
    std::shared_ptr<FileManager> _fileManager;
    
    AtlasMap _allAtlases;
    
    std::filesystem::path buildAtlasImagePath(std::string atlasName);
    std::filesystem::path buildAtlasDataPath(std::string atlasName);
  };
}
