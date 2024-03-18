//
//  SpriteAtlas.hpp
//  grumble
//
//  Created by Benjamin Wallis on 30/07/2023.
//

#pragma once

#include "../core/Object.hpp"
#include "../io/ImageFile.hpp"
#include "SpriteDefinition.hpp"
#include <nlohmann/json.hpp>

namespace grumble {
class SpriteAtlas : public Object {
public:
  typedef std::shared_ptr<SpriteAtlas> shared_ptr;
  typedef std::vector<shared_ptr> vector;
  typedef vector::iterator iterator;
  typedef vector::const_iterator const_iterator;

  SpriteAtlas(std::string name, nlohmann::json layout,
              ImageFile::shared_ptr file);

  const std::string name() const;
  ImageFile::shared_ptr file();

  const std::string toString() const override;

private:
  std::string _name;
  nlohmann::json _layout;
  ImageFile::shared_ptr _file;
};
} // namespace grumble
