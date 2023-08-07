//
//  ViewFactory.hpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#pragma once

#include <memory>

#include "../core/Object.hpp"

#include "../ui/View.hpp"
#include "../ui/ImageView.hpp"

#include "../sprite/Sprite.hpp"

#include "../render/RendererManager.hpp"

namespace grumble {
  class ViewFactory: public Object {
  public:
    typedef std::shared_ptr<ViewFactory> shared_ptr;
    
    ViewFactory();
    
    View::shared_ptr createView(glm::vec2 position = VECTOR_EMPTY,
                                glm::vec2 size = {0.0, 0.0},
                                TransformOrigin origin = TransformOrigin::TopLeft);
    ImageView::shared_ptr createImageView(std::shared_ptr<Sprite> sprite,
                                          glm::vec2 position = VECTOR_EMPTY,
                                          glm::vec2 size = {10.0f, 10.0},
                                          TransformOrigin origin = TransformOrigin::TopLeft);
  };
}
