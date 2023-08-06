//
//  SpriteManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "SpriteManager.hpp"

namespace grumble {
  SpriteManager::SpriteManager(SpriteManagerConfiguration configuration,
                               FileManager::shared_ptr fileManager) :
    _fileManager(fileManager),
    _configuration(configuration),
    _allAtlases() {
    
  }

  SpriteManager::~SpriteManager() {
    
  }

  void SpriteManager::setup() {
    logInfo("Setting up SpriteManager");
    
    SpriteManagerConfiguration::AtlasIterator iterator = _configuration.atlases.begin();
    for (; iterator != _configuration.atlases.end(); iterator++) {
      std::string atlasName = (*iterator);
      logInfo("Setting up atlas: {}", atlasName);
      
      std::filesystem::path atlasLayoutPath = buildAtlasDataPath(atlasName);
      std::filesystem::path atlasImagePath = buildAtlasImagePath(atlasName);
      auto atlasLayout = _fileManager->loadJson(atlasLayoutPath);
      ImageFile::shared_ptr atlasImage = _fileManager->loadPNG(atlasImagePath);
      
      SpriteAtlas::shared_ptr atlas = std::make_shared<SpriteAtlas>(atlasName, atlasLayout, atlasImage);
      std::pair<std::string,SpriteAtlas::shared_ptr> item = { atlasName, atlas };
      _allAtlases.insert(item);
      
      logDebug("Setup up atlas successfully: {}", atlas->toString());
    }
    
    logInfo("Successfully set up SpriteManager");
  }

  Sprite::shared_ptr SpriteManager::getSprite(std::string name, std::string atlas) {
    logDebug("Getting sprite: {} in atlas: {}", name, atlas);
    return _allAtlases.at(atlas)->getSprite(name);
  }

  LogCategory SpriteManager::logCategory() {
    return LogCategory::rendering;
  }

  std::filesystem::path SpriteManager::buildAtlasImagePath(std::string filename) {
    return _configuration.atlasPath / std::filesystem::path(filename + "-sheet.png");
  }

  std::filesystem::path SpriteManager::buildAtlasDataPath(std::string filename) {
    return _configuration.atlasPath / std::filesystem::path(filename + "-data.json");
  }

  const SpriteAtlas::vector SpriteManager::allAtlases() const {
    SpriteAtlas::vector allAtlases;
    AtlasMapConstIterator iterator = _allAtlases.begin();
    for (; iterator != _allAtlases.end(); ++iterator) {
      allAtlases.push_back(iterator->second);
    }
    return allAtlases;
  }
}
