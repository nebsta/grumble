//
//  FileManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include <nlohmann/json.hpp>

#include "FileHandler.hpp"
namespace grumble {
    class FileManager {
    public:
        FileManager(const FileHandler* fileHandler);
        ~FileManager();
        
        std::string loadFile(const std::string& filename) const;
        nlohmann::json loadJson(const std::string& filename) const;
    private:
        const std::unique_ptr<const FileHandler> _handler;
    };
}

#endif /* FileManager_hpp */
