//
//  ViewFactory.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "ViewFactory.hpp"

namespace grumble {
  ViewFactory::ViewFactory() { }

  std::shared_ptr<View> ViewFactory::createView(glm::vec2 position,
                                                glm::vec2 size,
                                                TransformOrigin origin) {
    return std::make_shared<View>(position, size, origin);
  }


  std::shared_ptr<ImageView> ViewFactory::createImageView(std::shared_ptr<Sprite> sprite,
                                                          glm::vec2 position,
                                                          glm::vec2 size,
                                                          TransformOrigin origin) {
    return std::make_shared<ImageView>(sprite, position, size, origin);
  }
}
