//
//  FontManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "FontManager.hpp"

namespace grumble {
  FontManager::FontManager(FileManager::shared_ptr fileManager, std::string mainFontFile):
    _fileManager(fileManager),
    _mainFontFile(mainFontFile) {
    
  }

  FontManager::~FontManager() {
    
  }

  void FontManager::setup() {
    FT_Library library;
    FT_Error error;
    FT_Face face;
    
    logInfo("Setting up FontManager");
    
    error = FT_Init_FreeType(&library);
    if (error) {
      logError("Could not init FreeType Library. Error: " + std::string(FT_Error_String(error)));
      return;
    }
    
    auto fontBuffer = _fileManager->loadFileRaw(_mainFontFile);
    
//    logInfo("File size: " + std::to_string(fontBuffer.size()));
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
//
//    error = FT_New_Memory_Face( library,
//                                buffer,    /* first byte in memory */
//                                size,      /* size in bytes        */
//                                0,         /* face_index           */
//                                &face );
//    if ( error ) { ... }
    
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


#pragma mark Protected Methods
  LogCategory FontManager::logCategory() {
    return LogCategory::font;
  }
}
