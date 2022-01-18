//
//  ShaderManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#include <stdio.h>
#include <string>
#include <map>

#include "Logger.hpp"
#include "ShaderHandler.hpp"

namespace grumble {
    using namespace std;

    class ShaderManager {
        
    public:
        static ShaderManager& instance() {
            static ShaderManager instance;
            return instance;
        }
        
        template<typename T>
        void initialize(ShaderHandler *handler);
        void teardown();
        
    private:
        unique_ptr<ShaderHandler> _shaderHandler;
        
        ShaderManager();
        ~ShaderManager();
    };
}

#endif /* ShaderManager_hpp */
