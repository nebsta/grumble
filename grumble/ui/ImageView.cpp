//
//  ImageView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ImageView.hpp"

namespace grumble {
  ImageView::ImageView(std::shared_ptr<Sprite> sprite,
                       glm::vec2 position,
                       glm::vec2 size,
                       glm::vec4 tint) :
    View(position, size),
    _sprite(sprite) {
    
  }

  ImageView::~ImageView() {
    
  }

  #pragma mark Setters

  void ImageView::setSprite(std::shared_ptr<Sprite> sprite) {
    _sprite = sprite;
  }
}
