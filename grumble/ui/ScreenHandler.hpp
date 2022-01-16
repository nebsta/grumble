//
//  ScreenHandler.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#ifndef ScreenHandler_hpp
#define ScreenHandler_hpp

#include <glm/glm.hpp>

namespace grumble {
    class ScreenHandler {
    public:
        
        virtual void initialize(const float& screenScale, const float& screenWith, const float& screenHeight) = 0;
        
        virtual glm::vec2 convertToPixels(const glm::vec2& vector) const = 0;
        
        virtual float screenScale() const = 0;
        virtual float screenWidth() const = 0;
        virtual float screenHeight() const = 0;
        
        virtual glm::vec2 screenPixelSize() const = 0;
        virtual glm::vec2 screenSize() const = 0;
    };

}

#endif /* ScreenHandler_hpp */
