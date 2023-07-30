//
//  SpriteAtlas.hpp
//  grumble
//
//  Created by Benjamin Wallis on 30/07/2023.
//

#pragma once

#include <nlohmann/json.hpp>
#include <map>

#include "Sprite.hpp"

#include "../core/Object.hpp"

namespace grumble {
  class SpriteAtlas: public Object {
  public:
    SpriteAtlas(std::string name,
                nlohmann::json layout,
                std::vector<char> data);
    
    std::shared_ptr<Sprite> getSprite(std::string name);
    
  private:
    std::string _name;
    nlohmann::json _layout;
    std::vector<char> _data;
    std::map<std::string, std::shared_ptr<Sprite>> _allSprites;
  };
}
