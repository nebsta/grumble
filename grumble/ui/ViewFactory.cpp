//
//  ViewFactory.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "ViewFactory.hpp"

namespace grumble {
  ViewFactory::ViewFactory() {
  }

  std::shared_ptr<View> ViewFactory::createView(glm::vec2 position, glm::vec2 size) {
    return std::make_shared<View>(position, size);
  }
}
