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
    typedef std::shared_ptr<SpriteAtlas> shared_ptr;
    typedef std::vector<std::shared_ptr<SpriteAtlas>>::iterator Iterator;
    typedef std::vector<std::shared_ptr<SpriteAtlas>>::const_iterator ConstIterator;
    
    typedef std::map<std::string, std::shared_ptr<Sprite>> SpriteMap;
    typedef SpriteMap::const_iterator SpriteMapConstIterator;
    
    SpriteAtlas(std::string name,
                nlohmann::json layout,
                std::shared_ptr<ImageFile> file);
    
    std::shared_ptr<Sprite> getSprite(std::string name);
    
    const std::string name() const;
    std::shared_ptr<ImageFile> file();
    
    const std::string toString() const override;
    std::vector<std::shared_ptr<Sprite>> allSprites() const;
    
  private:
    std::string _name;
    nlohmann::json _layout;
    std::shared_ptr<ImageFile> _file;
    SpriteMap _allSprites;
  };
}
