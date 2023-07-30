//
//  FileManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#include "FileManager.hpp"

namespace grumble {
  FileManager::FileManager(std::string rootpath) : _rootPath(rootpath) {
    
  }

  FileManager::~FileManager() {
    
  }

  std::string FileManager::loadFile(std::string filename) {
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return "";
    }
    
    auto fileSize = std::filesystem::file_size(path);
    
    logInfo("File size: " + std::to_string(fileSize));
    
    return "";
//    return _handler->loadFile(filename);
  }

  std::vector<char> FileManager::loadFileRaw(std::string filename) {
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return std::vector<char>();
    }
    
    std::ifstream infile(path, std::ios_base::binary);
    std::vector<char> buffer((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    return buffer;
  }

  nlohmann::json FileManager::loadJson(std::string filename) {
    std::string raw = loadFile(filename);
    return nlohmann::json::parse(raw);
  }

  std::filesystem::path FileManager::buildFilePath(std::filesystem::path filename) {
    return _rootPath / filename;
  }

  LogCategory FileManager::logCategory() {
    return LogCategory::io;
  }
}
