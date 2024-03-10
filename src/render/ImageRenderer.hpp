//
//  ImageRenderer.hpp
//  grumble
//
//  Created by Benjamin Wallis on 05/08/2023.
//

#pragma once

#include "../sprite/Sprite.hpp"
#include "Renderer.hpp"
#include "Shape.hpp"

namespace grumble {
class ImageRenderer : public Renderer {
public:
  typedef std::shared_ptr<ImageRenderer> shared_ptr;

  ImageRenderer(Sprite::shared_ptr sprite, Shape shape = SHAPE_SQUARE,
                RenderMethod renderMethod = RenderMethod::TriangleStrip);
  ~ImageRenderer();

  Sprite::shared_ptr sprite() const;

private:
  Sprite::shared_ptr _sprite;
};
} // namespace grumble
