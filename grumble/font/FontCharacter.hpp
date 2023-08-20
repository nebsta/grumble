//
//  FontCharacter.hpp
//  grumble
//
//  Created by Benjamin Wallis on 20/08/2023.
//

#pragma once

#include "../core/Object.hpp"

#include <glm/glm.hpp>

namespace grumble {
  class FontCharacter: public Object {
  public:
    typedef std::shared_ptr<FontCharacter> shared_ptr;
    
    FontCharacter(char character,
                  glm::ivec2 size,
                  glm::ivec2 bearing,
                  unsigned int advance);
    ~FontCharacter();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    char _character;
    glm::ivec2 _size;
    glm::ivec2 _bearing;
    unsigned int _advance;
  };
}
