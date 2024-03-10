//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"

namespace grumble {
void RendererManager::renderFrame(View::shared_ptr rootView) {
  this->renderView(rootView->transform(), rootView->renderer());

  if (!rootView->hasChildren()) {
    return;
  }

  View::iterator iter = rootView->childIteratorBegin();
  for (; iter != rootView->childIteratorEnd(); iter++) {
    auto view = *iter;
    switch (view->type()) {
    case ViewType::BaseType:
      this->renderView(view->transform(), view->renderer());
      break;
    case ViewType::ImageViewType:
      this->renderImageView(
          view->transform(),
          dynamic_pointer_cast<ImageRenderer>(view->renderer()));
      break;
    case ViewType::LabelViewType:
      this->renderLabel(view->transform(),
                        dynamic_pointer_cast<TextRenderer>(view->renderer()));
      break;
    }
  }
}

void RendererManager::setup(float renderScale) {
  logInfo("Setting up render manager with scale: {}", renderScale);
  _renderScale = renderScale;
  setup();
}

const float RendererManager::renderScale() const { return _renderScale; }

const glm::vec2 RendererManager::screenSize() const { return _screenSize; }

void RendererManager::setOnScreenSizeUpdated(
    ScreenSizeUpdated onScreenSizeUpdated) {
  _onScreenSizeUpdated = onScreenSizeUpdated;
}

#pragma mark Protected Methods

glm::mat4 RendererManager::submitScreenSize(glm::vec2 size) {
  logInfo("Screen size submitted: {}", glm::to_string(size));

  _screenSize = size;
  if (_onScreenSizeUpdated) {
    _onScreenSizeUpdated(size);
  }
  return glm::ortho(0.0f, float(size.x), float(size.y), 0.0f);
}

LogCategory RendererManager::logCategory() { return LogCategory::rendering; }
} // namespace grumble
