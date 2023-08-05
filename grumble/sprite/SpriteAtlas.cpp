//
//  SpriteAtlas.cpp
//  grumble
//
//  Created by Benjamin Wallis on 30/07/2023.
//

#include "SpriteAtlas.hpp"

namespace grumble {
  SpriteAtlas::SpriteAtlas(std::string name,
                           nlohmann::json layout,
                           std::shared_ptr<ImageFile> file) :
    _name(name),
    _layout(layout),
    _file(file) {
      
    auto frames = _layout["frames"];
    for (nlohmann::json::iterator it = frames.begin(); it != frames.end(); ++it) {
      std::string spriteName = (*it)["filename"];
      
      auto frameRegion = (*it)["frame"];
      SpriteRegion region = { frameRegion["x"], frameRegion["y"], frameRegion["w"], frameRegion["h"] };
      
      logDebug("Setting up sprite: {}", spriteName);
      
      std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(spriteName, _name, region);
      logDebug("");
      _allSprites[name] = sprite;
    }
  }

  std::shared_ptr<Sprite> SpriteAtlas::getSprite(std::string name) {
    return _allSprites[name];
  }

  const std::string SpriteAtlas::name() const {
    return _name;
  }

  std::shared_ptr<ImageFile> SpriteAtlas::file() {
    return _file;
  }
}
