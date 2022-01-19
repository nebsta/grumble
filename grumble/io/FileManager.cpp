//
//  FileManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#include "FileManager.hpp"

namespace grumble {
    FileManager::FileManager(const FileHandler* handler) :
    _handler(handler) {
        
    }

    FileManager::~FileManager() {
        
    }

    std::string FileManager::loadFile(const std::string& filename) const {
        return _handler->loadFile(filename);
    }

    nlohmann::json FileManager::loadJson(const std::string &filename) const {
        std::string raw = loadFile(filename);
        return nlohmann::json::parse(raw);
    }
}
