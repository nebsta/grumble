//
//  Font.cpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#include "Font.hpp"

namespace grumble {
  Font::Font() {

  }
             
  Font::~Font() {
    
  }

  void Font::setup(FT_Face face) {
    for (unsigned char c = 0; c < 128; c++) {
      logInfo("Loading glyph: {}", c);
      
      if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
        logError("Failed to load glyph {}", c);
        continue;
      }
      
      auto size = glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
      auto bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
      FT_Pos advance = face->glyph->advance.x;
      FontCharacter::shared_ptr character = std::make_shared<FontCharacter>(c, size, bearing, advance);
      
      FontCharacterItem item = { c, character };
      _characterMap.insert(item);
    }
  }

#pragma mark Protected Methods

  LogCategory Font::logCategory() {
    return LogCategory::font;
  }
}
