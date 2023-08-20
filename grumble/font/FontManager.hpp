//
//  FontManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#pragma once

#include "../core/Object.hpp"
#include "../io/FileManager.hpp"

#include "FontManagerConfiguration.hpp"
#include "Font.hpp"

namespace grumble {
  class FontManager: public Object {
  public:
    typedef std::shared_ptr<FontManager> shared_ptr;
    typedef std::map<std::string, Font::shared_ptr> FontMap;
    typedef std::pair<std::string, Font::shared_ptr> FontMapItem;
    
    FontManager(FontManagerConfiguration configuration,
                FileManager::shared_ptr fileManager);
    ~FontManager();
    
    void setup();
    
    Font::shared_ptr getFont(std::string name);
    Font::shared_ptr getMainFont();
    
    Font::vector allFonts();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    FontManagerConfiguration _configuration;
    FileManager::shared_ptr _fileManager;
    
    FontMap _allFonts;
    
    std::filesystem::path buildFontPath(std::string fontFile);
    
    const char* getErrorMessage(FT_Error err);
  };
}
