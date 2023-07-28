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
#include "../io/FileManager.hpp"

namespace grumble {
  class FontManager: public Object {
  public:
    FontManager(std::shared_ptr<FileManager> fileManager, std::string mainFontFile);
    ~FontManager();
    
    void setup();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    FT_Library _library;
    std::string _mainFontFile;
    std::shared_ptr<FileManager> _fileManager;
    
    const char* getErrorMessage(FT_Error err);
  };
}
