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
                           std::vector<char> data) :
    _name(name),
    _layout(layout),
    _data(data) {
      
    auto frames = _layout["frames"];
    for (nlohmann::json::iterator it = frames.begin(); it != frames.end(); ++it) {
      std::string name = (*it)["filename"];
      
      auto frameRegion = (*it)["frame"];
      Region region = { frameRegion["x"], frameRegion["y"], frameRegion["w"], frameRegion["h"] };
      std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(name, region);
      _allSprites[name] = sprite;
    }
  }

  std::shared_ptr<Sprite> SpriteAtlas::getSprite(std::string name) {
    return _allSprites[name];
  }
}
