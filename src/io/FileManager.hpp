//
//  FileManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <png.h>

#include "../core/Object.hpp"

#include "FileManagerConfiguration.hpp"
#include "ImageFile.hpp"

namespace grumble {
  class FileManager: public Object {
  public:
    typedef std::shared_ptr<FileManager> shared_ptr;
    
    FileManager(FileManagerConfiguration configuration);
    ~FileManager();
    
    std::string loadFile(std::filesystem::path filename);
    std::vector<char> loadFileRaw(std::filesystem::path filename);
    ImageFile::shared_ptr loadPNG(std::filesystem::path filename);
    nlohmann::json loadJson(std::filesystem::path filename);
    
    void writePNG(std::filesystem::path filename, ImageFile::shared_ptr file);
    
  protected:
    LogCategory logCategory() override;
    
  private:
    FileManagerConfiguration _configuration;
    
    std::filesystem::path buildReadPath(std::filesystem::path filename);
    std::filesystem::path buildWritePath(std::filesystem::path filename);
    
    static void pngError(png_structp png_ptr, png_const_charp error_msg);
    static void pngWarning(png_structp png_ptr, png_const_charp warning_msg);
  };
}
