//
//  SpriteHandler.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef SpriteHandler_hpp
#define SpriteHandler_hpp

#include <stdio.h>

#import "Sprite.h"

namespace grumble {
    using namespace std;

    class SpriteHandler {
        
    public:
        virtual ~SpriteHandler() { }
        
        virtual void loadAtlases() = 0;
        virtual Sprite loadSprite(const string& file, const string& spriteName) const = 0;
    };
}



#endif /* SpriteHandler_hpp */
