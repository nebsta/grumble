//
//  ViewFactory.cpp
//  grumble
//
//  Created by Benjamin Wallis on 22/07/2023.
//

#include "ViewFactory.hpp"

namespace grumble {
  ViewFactory::ViewFactory(std::shared_ptr<RendererManager> rendererManager) {
    _rendererManager = rendererManager;
  }

  ViewFactory::~ViewFactory() {
    
  }

  std::shared_ptr<View> ViewFactory::createView() {
    std::shared_ptr<Renderer> renderer = _rendererManager->createViewRenderer();
    return std::make_shared<View>(grumble::View(glm::vec2(0.0f, 0.0f), glm::vec2(10.0f, 10.0f), renderer));
  }
}

