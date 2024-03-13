//
//  ImageView.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ImageView.hpp"

namespace grumble {
ImageView::ImageView(uint32_t instanceId, Sprite::shared_ptr sprite,
                     glm::vec2 position, glm::vec2 size, TransformOrigin origin)
    : View(std::make_shared<ImageRenderer>(sprite, instanceId), position, size,
           origin, ViewType::ImageViewType),
      _sprite(sprite) {}

ImageView::~ImageView() {}

ImageRenderer::shared_ptr ImageView::imageRenderer() const {
  return dynamic_pointer_cast<ImageRenderer>(_renderer);
}

#pragma mark Setters

void ImageView::setSprite(Sprite::shared_ptr sprite) { _sprite = sprite; }
} // namespace grumble
