//
//  FontCharacter.cpp
//  grumble
//
//  Created by Benjamin Wallis on 20/08/2023.
//

#include "FontCharacter.hpp"

namespace grumble {
FontCharacter::FontCharacter(std::string font, char character,
                             SpriteRegion region, glm::ivec2 bearing,
                             unsigned int advance)
    : Object(fmt::format("{}-{}", font, (int)character)), _character(character),
      _region(region), _bearing(bearing), _advance(advance) {}

FontCharacter::~FontCharacter() {}

SpriteRegion FontCharacter::region() { return _region; }

glm::ivec2 FontCharacter::bearing() { return _bearing; }

const std::string FontCharacter::toString() const {
  return fmt::format(
      "id: {}, character: {}, region: {}, bearing: {}, advance: {}", _id,
      _character, _region.toString(), glm::to_string(_bearing), _advance);
}

#pragma mark Protected Methods
LogCategory FontCharacter::logCategory() const { return LogCategory::font; }
} // namespace grumble
