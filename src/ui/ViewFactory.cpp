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

ImageView::shared_ptr ViewFactory::createImageView(Sprite::shared_ptr sprite,
                                                   glm::vec2 position,
                                                   glm::vec2 size,
                                                   TransformOrigin origin) {
  uint32_t instanceId = generateInstanceId();
  return std::make_shared<ImageView>(instanceId, sprite, position, size,
                                     origin);
}

Label::shared_ptr ViewFactory::createLabel(std::string text,
                                           Font::shared_ptr font,
                                           glm::vec2 position,
                                           TransformOrigin origin) {
  if (font == nullptr) {
    font = _fontManager->getMainFont();
  }

  uint32_t instanceId = generateInstanceId();
  return std::make_shared<Label>(instanceId, text, font, position, origin);
}

uint32_t ViewFactory::generateInstanceId() {
  _runningInstanceId += 1;
  return _runningInstanceId;
}
} // namespace grumble
