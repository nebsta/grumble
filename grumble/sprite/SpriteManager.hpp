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
  typedef std::map<std::string, SpriteAtlas::shared_ptr> AtlasMap;
  typedef AtlasMap::const_iterator AtlasMapConstIterator;

  class SpriteManager: Object {
  public:
    typedef std::shared_ptr<SpriteManager> shared_ptr;
    
    SpriteManager(SpriteManagerConfiguration configuration,
                  FileManager::shared_ptr fileManager);
    ~SpriteManager();
    
    void setup();
    
    Sprite::shared_ptr getSprite(std::string name, std::string atlas);
    
    const SpriteAtlas::vector allAtlases() const;
    
  protected:
    LogCategory logCategory() override;
    
  private:
    SpriteManagerConfiguration _configuration;
    FileManager::shared_ptr _fileManager;
    
    AtlasMap _allAtlases;
    
    std::filesystem::path buildAtlasImagePath(std::string atlasName);
    std::filesystem::path buildAtlasDataPath(std::string atlasName);
  };
}
