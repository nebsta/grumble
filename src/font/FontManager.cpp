//
//  FontManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "FontManager.hpp"

namespace grumble {
FontManager::FontManager(FontManagerConfiguration configuration,
                         FileManager::shared_ptr fileManager)
    : _configuration(configuration), _fileManager(fileManager) {}

FontManager::~FontManager() {}

void FontManager::setup() {
  FT_Library library;
  FT_Error error;

  logInfo("Setting up FontManager");

  error = FT_Init_FreeType(&library);
  if (error) {
    logError("Could not init FreeType Library. Error: " +
             std::string(FT_Error_String(error)));
    return;
  }

  FontManagerConfiguration::FontIterator iter = _configuration.fonts.begin();
  for (; iter != _configuration.fonts.end(); ++iter) {
    std::string fontName = *iter;
    std::filesystem::path fontPath = buildFontPath(fontName);
    logInfo("Setting up font: {}", fontName);

    FT_Face face;

    auto fontBuffer = _fileManager->loadFileRaw(fontPath);
    FT_Byte *bytes = (FT_Byte *)fontBuffer.data();
    error = FT_New_Memory_Face(library, bytes, fontBuffer.size(), 0, &face);
    FT_Set_Pixel_Sizes(face, 0, 48);

    if (error) {
      std::string str = getErrorMessage(error);
      logError("Error when loading main font file. Error: " + str);
      return;
    }

    Font::shared_ptr font = std::make_shared<Font>(fontName);
    font->setup(face);
    _allFonts.insert({fontName, font});

    FT_Done_Face(face);
  }

  FT_Done_FreeType(library);
  logInfo("FontManager setup successfully");
}

const char *FontManager::getErrorMessage(FT_Error err) {
#undef FTERRORS_H_
#define FT_ERRORDEF(e, v, s)                                                   \
  case e:                                                                      \
    return s;
#define FT_ERROR_START_LIST switch (err) {
#define FT_ERROR_END_LIST }
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

Font::vector FontManager::allFonts() {
  Font::vector allFonts;
  FontMap::iterator iterator = _allFonts.begin();
  for (; iterator != _allFonts.end(); ++iterator) {
    allFonts.push_back(iterator->second);
  }
  return allFonts;
}

#pragma mark Protected Methods

LogCategory FontManager::logCategory() const { return LogCategory::font; }
} // namespace grumble
