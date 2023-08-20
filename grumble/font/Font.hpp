//
//  Font.hpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../core/Object.hpp"

namespace grumble {
  class Font: public Object {
  public:
    typedef std::shared_ptr<Font> shared_ptr;
    
    Font(FT_Face face);
    ~Font();
  private:
    
    FT_Face _face;
  };
}
