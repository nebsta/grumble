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
#include "ImageFile.hpp"

namespace grumble {
  class FileManager: public Object {
  public:
    typedef std::shared_ptr<FileManager> shared_ptr;
    
    FileManager(std::string rootPath);
    ~FileManager();
    
    std::string loadFile(std::filesystem::path filename);
    std::vector<char> loadFileRaw(std::filesystem::path filename);
    ImageFile::shared_ptr loadPNG(std::filesystem::path filename);
    nlohmann::json loadJson(std::filesystem::path filename);
    
  protected:
    LogCategory logCategory() override;
    
  private:
    std::string _rootPath;
    
    std::filesystem::path buildFilePath(std::filesystem::path filename);
    
    static void pngError(png_structp png_ptr, png_const_charp error_msg);
    static void pngWarning(png_structp png_ptr, png_const_charp warning_msg);
  };
}
