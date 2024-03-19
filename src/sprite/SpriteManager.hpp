//
//  SpriteManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>
#include <map>
#include <string_view>

#include "SpriteManagerConfiguration.hpp"

#include "../io/FileManager.hpp"

namespace grumble {

class SpriteManager : Object {
public:
  typedef std::shared_ptr<SpriteManager> shared_ptr;
  typedef std::map<std::string_view, ImageFile::shared_ptr> atlas_map;
  typedef atlas_map::const_iterator atlas_map_iter;

  SpriteManager(SpriteManagerConfiguration configuration,
                FileManager::shared_ptr fileManager);
  ~SpriteManager();

  void loadAtlas(std::string_view atlasName);
  void setup();

  ImageFile::weak_ptr getAtlasData(std::string_view atlas) const;

protected:
  LogCategory logCategory() const override;

private:
  atlas_map _loadedAtlases;

  SpriteManagerConfiguration _configuration;
  FileManager::shared_ptr _fileManager;

  bool atlasLoaded(std::string_view atlas) const;
};
} // namespace grumble
