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
#include <string>

#include "SpriteAtlas.hpp"
#include "SpriteManagerConfiguration.hpp"

#include "../io/FileManager.hpp"

namespace grumble {
typedef std::map<std::string, SpriteAtlas::shared_ptr> AtlasMap;
typedef AtlasMap::const_iterator AtlasMapConstIterator;

class SpriteManager : Object {
public:
  typedef std::shared_ptr<SpriteManager> shared_ptr;

  SpriteManager(SpriteManagerConfiguration configuration,
                FileManager::shared_ptr fileManager);
  ~SpriteManager();

  void setup();

  const SpriteAtlas::vector allAtlases() const;

protected:
  LogCategory logCategory() const override;

private:
  SpriteManagerConfiguration _configuration;
  FileManager::shared_ptr _fileManager;

  AtlasMap _allAtlases;

  std::filesystem::path buildAtlasImagePath(std::string atlasName);
  std::filesystem::path buildAtlasDataPath(std::string atlasName);
};
} // namespace grumble
