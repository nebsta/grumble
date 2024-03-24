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

ImageView::unique_ptr ViewFactory::createImageView(HMM_Vec2 position,
                                                   HMM_Vec2 size,
                                                   TransformOrigin origin) {

  uint32_t instanceId = generateInstanceId();
  return std::make_unique<ImageView>(instanceId, position, size, origin);
}

uint32_t ViewFactory::generateInstanceId() {
  _runningInstanceId += 1;
  return _runningInstanceId;
}
} // namespace grumble
