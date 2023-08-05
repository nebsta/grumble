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
#include "../io/ImageFile.hpp"

namespace grumble {
  class SpriteAtlas: public Object {
  public:
    typedef std::vector<std::shared_ptr<SpriteAtlas>>::iterator Iterator;
    
    SpriteAtlas(std::string name,
                nlohmann::json layout,
                std::shared_ptr<ImageFile> file);
    
    std::shared_ptr<Sprite> getSprite(std::string name);
    
    const std::string name() const;
    std::shared_ptr<ImageFile> file();
    
  private:
    std::string _name;
    nlohmann::json _layout;
    std::shared_ptr<ImageFile> _file;
    std::map<std::string, std::shared_ptr<Sprite>> _allSprites;
  };
}
