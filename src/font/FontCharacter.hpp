//
//  FontCharacter.hpp
//  grumble
//
//  Created by Benjamin Wallis on 20/08/2023.
//

#pragma once

#include "../core/Object.hpp"
#include "../sprite/SpriteRegion.hpp"

#include <glm/glm.hpp>

namespace grumble {
class FontCharacter : public Object {
public:
  typedef std::shared_ptr<FontCharacter> shared_ptr;
  typedef std::vector<shared_ptr> vector;

  FontCharacter(std::string font, char character, SpriteRegion region,
                glm::ivec2 bearing, unsigned int advance);
  ~FontCharacter();

  SpriteRegion region();
  glm::ivec2 bearing();

  const std::string toString() const override;

protected:
  LogCategory logCategory() override;

private:
  char _character;
  SpriteRegion _region;
  glm::ivec2 _bearing;
  unsigned int _advance;
};
} // namespace grumble
