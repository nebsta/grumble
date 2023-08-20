//
//  FontManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "FontManager.hpp"

namespace grumble {
  FontManager::FontManager(FontManagerConfiguration configuration,
                           FileManager::shared_ptr fileManager) :
    _configuration(configuration),
    _fileManager(fileManager) {
    
  }

  FontManager::~FontManager() {
    
  }

  void FontManager::setup() {
    FT_Library library;
    FT_Error error;
    
    logInfo("Setting up FontManager");
    
    error = FT_Init_FreeType(&library);
    if (error) {
      logError("Could not init FreeType Library. Error: " + std::string(FT_Error_String(error)));
      return;
    }
    
    FontManagerConfiguration::FontIterator iter = _configuration.fonts.begin();
    for (; iter != _configuration.fonts.end(); ++iter) {
      std::string fontName = *iter;
      std::filesystem::path fontPath = buildFontPath(fontName);
      logInfo("Setting up font: {}", fontName);
      
      FT_Face face;
      
      auto fontBuffer = _fileManager->loadFileRaw(fontPath);
      FT_Byte* bytes = (FT_Byte*)fontBuffer.data();
      error = FT_New_Memory_Face(library,
                                 bytes,
                                 fontBuffer.size(),
                                 0,
                                 &face);
      
      if (error) {
        std::string str = getErrorMessage(error);
        logError("Error when loading main font file. Error: " + str);
        return;
      }
      
      FontMapItem item = { fontName, std::make_shared<Font>(face) };
      _allFonts.insert(item);
    }
    
    logInfo("FontManager setup successfully");
  }

  const char* FontManager::getErrorMessage(FT_Error err) {
      #undef FTERRORS_H_
      #define FT_ERRORDEF( e, v, s )  case e: return s;
      #define FT_ERROR_START_LIST     switch (err) {
      #define FT_ERROR_END_LIST       }
      #include FT_ERRORS_H
      return "(Unknown error)";
  }

  Font::shared_ptr FontManager::getFont(std::string name) {
    return _allFonts.at(name);
  }

  Font::shared_ptr FontManager::getMainFont() {
    return _allFonts.at(_configuration.mainFont);
  }

  std::filesystem::path FontManager::buildFontPath(std::string fontFile) {
    return _configuration.fontPath / std::filesystem::path(fontFile);
  }


#pragma mark Protected Methods
  LogCategory FontManager::logCategory() {
    return LogCategory::font;
  }
}
