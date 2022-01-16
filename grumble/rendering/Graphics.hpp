//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef Graphics_hpp
#define Graphics_hpp

#include <stdio.h>

#include "Renderer.hpp"
#include "Sprite.h"

namespace grumble {
    class Graphics {
    public:
        static void Initialize();
        static Renderer* CreateViewRenderer(const glm::vec4& tint);
        static Renderer* CreateImageRenderer(const Sprite& sprite, const glm::vec4& tint);
        
    };
}

#endif /* Graphics_hpp */
