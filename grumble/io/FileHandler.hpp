//
//  FileHandler.hpp
//  grumble
//
//  Created by Benjamin Wallis on 19/01/2022.
//

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <stdio.h>
#include <string>

namespace grumble {
    class FileHandler {
    public:
        virtual std::string loadFile(const std::string& filename) const = 0;
        virtual ~FileHandler() = 0;
    };
}

#endif /* FileHandler_hpp */
