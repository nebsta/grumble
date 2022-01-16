//
//  ImageView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ImageView.hpp"

namespace grumble {
    ImageView::ImageView() : ImageView(SpriteEmpty) {
        
    }

    ImageView::ImageView(const Sprite& sprite) : ImageView(sprite,IMAGEVIEW_DEFAULT_POSITION) {
        
    }

    ImageView::ImageView(const Sprite& sprite, const glm::vec2& position) : ImageView(sprite,position,glm::vec2(sprite.region.w,sprite.region.h)) {
        
    }

    ImageView::ImageView(const Sprite& sprite, const glm::vec2& position, const glm::vec2& size) : ImageView(sprite, position, size, IMAGEVIEW_DEFAULT_COLOR) {
        
    }

    ImageView::ImageView(const Sprite& sprite, const glm::vec2& position, const glm::vec2& size, const glm::vec4& tint) : ImageView(position, size, Graphics::CreateImageRenderer(sprite, tint)) {
        
    }

    ImageView::ImageView(const glm::vec2& position, const glm::vec2& size, Renderer * const renderer) : View(position, size, renderer) {
        
    }

    ImageView::~ImageView() {
        
    }

    #pragma mark Setters

    void ImageView::setSprite(Sprite sprite) {
    //    ((ImageViewRenderer&)_renderer).setSprite(sprite);
    }
}
