//
//  ImageRenderer.cpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#include "ImageRenderer.hpp"

namespace grumble {
  ImageRenderer::ImageRenderer(std::shared_ptr<Sprite> sprite,
                               RenderMethod renderMethod) :
    Renderer(renderMethod),
    _sprite(sprite) {
    
  }

  ImageRenderer::~ImageRenderer() {
    
  }


  std::shared_ptr<Sprite> ImageRenderer::sprite() const {
    return _sprite;
  }
}
