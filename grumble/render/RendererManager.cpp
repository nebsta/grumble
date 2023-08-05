//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"

namespace grumble {
  void RendererManager::renderAll(std::shared_ptr<View> rootView) {
    this->renderView(rootView->transform(), rootView->renderer());
    
    if (!rootView->hasChildren()) {
      return;
    }
    
    for (View::Iterator iter = rootView->childIteratorBegin(); iter != rootView->childIteratorEnd(); iter++) {
      auto view = *iter;
      
      if (typeid(view) == typeid(View)) {
        this->renderView(view->transform(), view->renderer());
      } else if (typeid(view) == typeid(ImageView)) {
        this->renderImageView(view->transform(), dynamic_pointer_cast<ImageRenderer>(view->renderer()));
      }
    }
  }

  void RendererManager::setup(float renderScale) {
    logInfo("Setting up render manager with scale: " + std::to_string(renderScale));
    _renderScale = renderScale;
    setup();
  }

  const float RendererManager::renderScale() const {
    return _renderScale;
  }

  const glm::vec2 RendererManager::screenSize() const {
    return _screenSize;
  }

  void RendererManager::setOnScreenSizeUpdated(ScreenSizeUpdated onScreenSizeUpdated) {
    _onScreenSizeUpdated = onScreenSizeUpdated;
  }

#pragma mark Protected Methods

  glm::mat4 RendererManager::submitScreenSize(glm::vec2 size) {
    logInfo("Screen size submitted: " + glm::to_string(size));
    
    _screenSize = size;
    if (_onScreenSizeUpdated) {
      _onScreenSizeUpdated(size);
    }
    return glm::ortho(0.0f, float(size.x), float(size.y), 0.0f);
  }

  LogCategory RendererManager::logCategory() {
    return LogCategory::rendering;
  }
}

