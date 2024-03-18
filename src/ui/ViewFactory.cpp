//
//  ViewFactory.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "ViewFactory.hpp"

namespace grumble {
ViewFactory::ViewFactory(FontManager::shared_ptr fontManager)
    : _fontManager(fontManager) {}

View::shared_ptr ViewFactory::createView(glm::vec2 position, glm::vec2 size,
                                         TransformOrigin origin) {

  uint32_t instanceId = generateInstanceId();
  return std::make_shared<View>(instanceId, position, size, origin);
}

uint32_t ViewFactory::generateInstanceId() {
  _runningInstanceId += 1;
  return _runningInstanceId;
}
} // namespace grumble
