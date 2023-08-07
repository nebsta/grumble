//
//  ViewFactory.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "ViewFactory.hpp"

namespace grumble {
  ViewFactory::ViewFactory() { }

  View::shared_ptr ViewFactory::createView(glm::vec2 position,
                                                glm::vec2 size,
                                                TransformOrigin origin) {
    return std::make_shared<View>(position, size, origin);
  }


  ImageView::shared_ptr ViewFactory::createImageView(Sprite::shared_ptr sprite,
                                                     glm::vec2 position,
                                                     glm::vec2 size,
                                                     TransformOrigin origin) {
    return std::make_shared<ImageView>(sprite, position, size, origin);
  }
}
