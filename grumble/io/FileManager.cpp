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

  std::string FileManager::loadFile(std::filesystem::path filename) {
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return "";
    }
    
    std::ifstream file(path);
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return str;
  }

  std::vector<char> FileManager::loadFileRaw(std::filesystem::path filename) {
    std::filesystem::path path = buildFilePath(filename);
    if (!std::filesystem::exists(path)) {
      logError("File at path " + path.string() + " doesn't exist.");
      return std::vector<char>();
    }
    
    std::ifstream file(path, std::ios_base::binary);
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return buffer;
  }

  nlohmann::json FileManager::loadJson(std::filesystem::path filename) {
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
