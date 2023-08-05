//
//  ImageRenderer.hpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#pragma once

#include "Renderer.hpp"
#include "../sprite/Sprite.hpp"

namespace grumble {
  class ImageRenderer: public Renderer {
  public:
    
    ImageRenderer(std::shared_ptr<Sprite> sprite,
                  RenderMethod renderMethod = RenderMethod::TriangleStrip);
    ~ImageRenderer();
    
    std::shared_ptr<Sprite> sprite() const;
    
  private:
    std::shared_ptr<Sprite> _sprite;
  };
}
