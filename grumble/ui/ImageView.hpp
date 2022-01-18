//
//  ImageView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef ImageView_hpp
#define ImageView_hpp

#include <stdio.h>

#include "View.hpp"
#include "Sprite.hpp"
#include "MathConstants.hpp"
#include "Graphics.hpp"

#define IMAGEVIEW_DEFAULT_POSITION VECTOR_EMPTY
#define IMAGEVIEW_DEFAULT_COLOR COLOR_WHITE

namespace grumble {
    class ImageView : public View {
        
    public:
        ImageView();
        ImageView(const Sprite& sprite);
        ImageView(const Sprite& sprite, const glm::vec2& position);
        ImageView(const Sprite& sprite, const glm::vec2& position, const glm::vec2& size);
        ImageView(const Sprite& sprite, const glm::vec2& position, const glm::vec2& size, const glm::vec4& tint);
        ImageView(const glm::vec2& position, const glm::vec2& size, Renderer * const renderer);
        ~ImageView();
        
        void setSprite(Sprite sprite);
    private:
    };
}

#endif /* ImageView_hpp */
