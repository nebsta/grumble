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

ImageView::unique_ptr
ViewFactory::createImageView(const SpriteDefinition &sprite, HMM_Vec2 position,
                             HMM_Vec2 size, TransformOrigin origin) {

  uint32_t instanceBufferId = createInstanceBufferId();
  return std::make_unique<ImageView>(instanceBufferId, sprite, position, size,
                                     origin);
}

uint32_t ViewFactory::createInstanceBufferId() {
  _runningInstanceId += 1;
  return _runningInstanceId;
}
} // namespace grumble
