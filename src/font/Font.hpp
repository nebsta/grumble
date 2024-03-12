//
//  Font.hpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#pragma once

#include <ft2build.h>
#include <map>
#include FT_FREETYPE_H

#include "../core/Object.hpp"
#include "../io/ImageFile.hpp"

#include "FontCharacter.hpp"

#define CHARACTER_TOTAL 58
#define ATLAS_SIZE glm::vec2(256, 256)

namespace grumble {
class Font : public Object {
public:
  typedef std::shared_ptr<Font> shared_ptr;
  typedef std::map<char, FontCharacter::shared_ptr> FontCharacterMap;
  typedef std::pair<char, FontCharacter::shared_ptr> FontCharacterItem;
  typedef std::vector<shared_ptr> vector;
  typedef vector::iterator iterator;

  Font(std::string name);
  ~Font();

  void setup(FT_Face face);

  std::shared_ptr<unsigned char> data();
  int atlasWidth();
  int atlasHeight();
  int bytesPerRow();
  std::string name();

  FontCharacter::vector allCharacters();

  const std::string toString() const override;

  std::shared_ptr<ImageFile> generateAtlasImage();

protected:
  LogCategory logCategory() const override;

private:
  FontCharacterMap _characterMap;
  std::vector<unsigned char> _data;
  std::string _name;
};
} // namespace grumble
