//
//  Font.hpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#pragma once

#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../core/Object.hpp"

#include "FontCharacter.hpp"

namespace grumble {
  class Font: public Object {
  public:
    typedef std::shared_ptr<Font> shared_ptr;
    typedef std::map<char, FontCharacter::shared_ptr> FontCharacterMap;
    typedef std::pair<char, FontCharacter::shared_ptr> FontCharacterItem;
    
    Font();
    ~Font();
    
    void setup(FT_Face face);
    
  protected:
    LogCategory logCategory() override;
    
  private:
    FontCharacterMap _characterMap;
  };
}
