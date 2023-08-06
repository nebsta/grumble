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
      
      std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(spriteName, _name, region);
      std::pair<std::string,std::shared_ptr<Sprite>> item = { spriteName, sprite };
      logDebug("Setting up sprite: {}", sprite->toString());
      _allSprites.insert(item);
    }
  }

  std::shared_ptr<Sprite> SpriteAtlas::getSprite(std::string name) {
    return _allSprites.at(name);
  }

  const std::string SpriteAtlas::name() const {
    return _name;
  }

  std::shared_ptr<ImageFile> SpriteAtlas::file() {
    return _file;
  }

  const std::string SpriteAtlas::toString() const {
    std::string spritesString = "[";
    auto iter = _allSprites.begin();
    for (; iter != _allSprites.end(); iter++) {
      spritesString += fmt::format("{}," ,(*iter).second->toString());
    }
    spritesString += "]";
    
    return fmt::format("id: {}, name: {}, sprites: {}", _id, _name, spritesString);
  }
}
