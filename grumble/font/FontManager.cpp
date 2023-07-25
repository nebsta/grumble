//
//  FontManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "FontManager.hpp"

namespace grumble {
  FontManager::FontManager() {
    
  }

  FontManager::~FontManager() {
    
  }

  void FontManager::setup() {
    if (FT_Init_FreeType(&_library)) {
      logError("Could not init FreeType Library");
      return;
    }
  }

#pragma mark Protected Methods
  LogCategory FontManager::logCategory() {
    return LogCategory::font;
  }
}
