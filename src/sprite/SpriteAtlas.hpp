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
    typedef std::vector<shared_ptr> vector;
    typedef vector::iterator iterator;
    typedef vector::const_iterator const_iterator;
    
    typedef std::map<std::string, Sprite::shared_ptr> SpriteMap;
    typedef SpriteMap::const_iterator SpriteMapConstIterator;
    
    SpriteAtlas(std::string name,
                nlohmann::json layout,
                ImageFile::shared_ptr file);
    
    Sprite::shared_ptr getSprite(std::string name);
    
    const std::string name() const;
    ImageFile::shared_ptr file();
    
    const std::string toString() const override;
    Sprite::vector allSprites() const;
    
  private:
    std::string _name;
    nlohmann::json _layout;
    ImageFile::shared_ptr _file;
    SpriteMap _allSprites;
  };
}
