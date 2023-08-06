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
                           ImageFile::shared_ptr file) :
    _name(name),
    _layout(layout),
    _file(file) {
      
    auto frames = _layout["frames"];
    auto atlasSize = _layout["meta"]["size"];
    float atlasWidth = atlasSize["w"];
    float atlasHeight = atlasSize["h"];
    for (nlohmann::json::iterator it = frames.begin(); it != frames.end(); ++it) {
      std::string spriteName = (*it)["filename"];
      
      logInfo("Setting up sprite: {}", spriteName);
      
      auto frameRegion = (*it)["frame"];
      
      float xPos = frameRegion["x"];
      float yPos = frameRegion["y"];
      float width = frameRegion["w"];
      float height = frameRegion["h"];
      SpriteRegion region = {
        { xPos / atlasWidth, yPos / atlasHeight },
        { xPos + width / atlasWidth, yPos / atlasHeight },
        { xPos / atlasWidth, yPos + height / atlasHeight },
        { xPos + width / atlasWidth, yPos + height / atlasHeight },
      };
      
      Sprite::shared_ptr sprite = std::make_shared<Sprite>(spriteName, _name, region);
      std::pair<std::string,Sprite::shared_ptr> item = { spriteName, sprite };
      _allSprites.insert(item);
      
      logDebug("Set up sprite successfully: {}", sprite->toString());
    }
  }

  std::shared_ptr<Sprite> SpriteAtlas::getSprite(std::string name) {
    return _allSprites.at(name);
  }

  const std::string SpriteAtlas::name() const {
    return _name;
  }

  ImageFile::shared_ptr SpriteAtlas::file() {
    return _file;
  }

  Sprite::vector SpriteAtlas::allSprites() const{
    Sprite::vector allSprites;
    SpriteMapConstIterator iterator = _allSprites.begin();
    for (; iterator != _allSprites.end(); ++iterator) {
      allSprites.push_back(iterator->second);
    }
    return allSprites;
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
