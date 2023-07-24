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
#include "../render/RendererManager.hpp"

namespace grumble {
  class ViewFactory: public Object {
  public:
    ViewFactory();
    
    std::shared_ptr<View> createView(glm::vec2 position, glm::vec2 size, TransformOrigin origin = TransformOrigin::TopLeft);
  };
}
