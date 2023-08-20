//
//  Font.cpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#include "Font.hpp"

namespace grumble {
  Font::Font(std::string name): _name(name) {

  }
             
  Font::~Font() {
    
  }

  void Font::setup(FT_Face face) {
    std::vector<unsigned char*> buffers;
    
    int maxRowHeight = 0;
    int rowWidth = 0;
    int yPos = 0;
    int xPos = 0;
    for (unsigned char c = 0; c < CHARACTER_TOTAL; c++) {
      logInfo("Loading glyph: {}", c);
      
      if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
        logError("Failed to load glyph {}", c);
        continue;
      }
      
      auto size = glm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
      auto bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
      FT_Pos advance = face->glyph->advance.x;
      auto atlasPos = glm::vec2(xPos, yPos);
      SpriteRegion region = { {xPos, yPos}, { xPos + size.x, size.y }, { xPos, yPos + size.y }, { xPos + size.x, yPos + size.y } };
      FontCharacter::shared_ptr character = std::make_shared<FontCharacter>(_name,
                                                                            c,
                                                                            region,
                                                                            bearing,
                                                                            advance);
                        

      
      logInfo("Loaded glyph: {}", character->toString());
      FontCharacterItem item = { c, character };
      _characterMap.insert(item);
      
      maxRowHeight = fmax(size.y, maxRowHeight);
      
      _data.push_back(face->glyph->bitmap.buffer);
      rowWidth += size.x;
      xPos += size.x;
      if (rowWidth >= ATLAS_SIZE.x) {
        rowWidth = 0;
        xPos = 0;
        yPos += maxRowHeight;
        maxRowHeight = 0;
      }
    }
  }

  std::vector<unsigned char*> Font::data() {
    return _data;
  }

  std::string Font::name() {
    return _name;
  }

  const std::string Font::toString() const {
    return _name;
  }

  int Font::atlasWidth() {
    return ATLAS_SIZE.x;
  }

  int Font::atlasHeight() {
    return ATLAS_SIZE.y;
  }

  int Font::bytesPerRow() {
    return ATLAS_SIZE.x;
  }

  FontCharacter::vector Font::allCharacters() {
    FontCharacter::vector allCharacters;
    FontCharacterMap::iterator iterator = _characterMap.begin();
    for (; iterator != _characterMap.end(); ++iterator) {
      allCharacters.push_back(iterator->second);
    }
    return allCharacters;
  }

#pragma mark Protected Methods

  LogCategory Font::logCategory() {
    return LogCategory::font;
  }
}
