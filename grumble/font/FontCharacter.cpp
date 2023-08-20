//
//  FontCharacter.cpp
//  grumble
//
//  Created by Benjamin Wallis on 20/08/2023.
//

#include "FontCharacter.hpp"

namespace grumble {
  FontCharacter::FontCharacter(char character,
                               glm::ivec2 size,
                               glm::ivec2 bearing,
                               unsigned int advance):
    _character(character),
    _size(size),
    _bearing(bearing),
    _advance(advance) {
    
  }

  FontCharacter::~FontCharacter() {
    
  }

#pragma mark Protected Methods
  LogCategory FontCharacter::logCategory() {
    return LogCategory::font;
  }
}
