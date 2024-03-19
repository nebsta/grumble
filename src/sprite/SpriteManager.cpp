//
//  SpriteManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "SpriteManager.hpp"
#include <filesystem>
#include <fmt/core.h>
#include <memory>
#include <string_view>
#include <vector>

namespace grumble {
SpriteManager::SpriteManager(SpriteManagerConfiguration configuration,
                             FileManager::shared_ptr fileManager)
    : _fileManager(fileManager), _configuration(configuration) {}

SpriteManager::~SpriteManager() {}

void SpriteManager::setup() {
  if (_configuration.preloadedAtlases.size() == 0) {
    logInfo("No preloaded atlases defined. Nothing to do.");
    return;
  }

  std::vector<std::string_view>::iterator iter =
      _configuration.preloadedAtlases.begin();
  for (; iter != _configuration.preloadedAtlases.end(); iter++) {
    std::string_view atlasName = (*iter);
    logInfo("Preloading atlas: {}", atlasName);
    loadAtlas(atlasName);
  }
}

LogCategory SpriteManager::logCategory() const {
  return LogCategory::rendering;
}

void SpriteManager::loadAtlas(std::string_view atlasName) {
  if (atlasLoaded(atlasName)) {
    logWarn("Trying to load atlas {} when it's already been loaded", atlasName);
    return;
  }

  std::filesystem::path atlasPath =
      _configuration.atlasPath / fmt::format("{}.png", atlasName);
  std::unique_ptr<ImageFile> loadedFile = _fileManager->loadPNG(atlasPath);
  if (loadedFile == nullptr) {
    logError("Error loading atlas file at path {}", atlasPath.string());
    return;
  }

  logInfo("Loaded atlas successfully at path {}", atlasPath.string());
  _loadedAtlases[atlasName] = std::move(loadedFile);
}

ImageFile::weak_ptr SpriteManager::getAtlasData(std::string_view atlas) const {
  atlas_map_iter iter = _loadedAtlases.find(atlas);
  if (iter == _loadedAtlases.end()) {
    logError("Trying to get loaded atlas data when it doesn't exist");
    return std::weak_ptr<ImageFile>();
  }

  return iter->second;
}

bool SpriteManager::atlasLoaded(std::string_view atlas) const {
  return _loadedAtlases.find(atlas) != _loadedAtlases.end();
}
} // namespace grumble
