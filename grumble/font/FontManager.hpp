//
//  FontManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../core/Object.hpp"

namespace grumble {
  class FontManager: public Object {
  public:
    FontManager();
    ~FontManager();
    
    void setup();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    FT_Library _library;
  };
}
