//
//  SpriteManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef SpriteManager_hpp
#define SpriteManager_hpp

#include <stdio.h>
#include <string>
#include <glm/glm.hpp>
#include <map>

#include "Sprite.hpp"
#include "SpriteHandler.hpp"
#include "../util/Logger.hpp"

namespace grumble {
    class SpriteManager {
        
    public:
        SpriteManager(SpriteHandler* handler);
        ~SpriteManager();
        
        Sprite loadSprite(const string& file, const string& spriteName) const;
        
    private:
        std::unique_ptr<SpriteHandler> _spriteHandler;
        
        std::map<string, std::map<std::string,Region>> _allAtlases;
        
        void parseAtlas(std::string file);
        glm::vec2 parseAtlasSize(const char * const raw);
    };
}

#endif /* SpriteManager_hpp */
