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

#include "../core/Object.hpp"

namespace grumble {
  class FileManager: public Object {
  public:
    FileManager(std::string rootPath);
    ~FileManager();
    
    std::string loadFile(std::string filename);
    std::vector<char> loadFileRaw(std::string filename);
    nlohmann::json loadJson(std::string filename);
    
  protected:
    LogCategory logCategory() override;
    
  private:
    std::string _rootPath;
    
    std::filesystem::path buildFilePath(std::string filename);
  };
}
