//
//  ImageRenderer.cpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#include "ImageRenderer.hpp"

namespace grumble {
  ImageRenderer::ImageRenderer(Sprite::shared_ptr sprite,
                               RenderMethod renderMethod) :
    Renderer(renderMethod),
    _sprite(sprite) {
    
  }

  ImageRenderer::~ImageRenderer() {
    
  }

  Sprite::shared_ptr ImageRenderer::sprite() const {
    return _sprite;
  }
}