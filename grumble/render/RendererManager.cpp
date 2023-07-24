//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"

namespace grumble {
  void RendererManager::renderAll(std::shared_ptr<View> rootView) {
    this->render(rootView);
    
    if (!rootView->hasChildren()) {
      return;
    }
    
    for (View::Iterator iter = rootView->childIteratorBegin(); iter != rootView->childIteratorEnd(); iter++) {
      this->render(*iter);
    }
  }

  void RendererManager::setup(float renderScale) {
    _renderScale= renderScale;
  }

  const float RendererManager::renderScale() const {
    return _renderScale;
  }
}

