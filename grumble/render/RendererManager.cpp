//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"

namespace grumble {
  void RendererManager::renderAll(std::shared_ptr<View> rootView) {
    if (!rootView->hasChildren()) {
      this->render(rootView);
      return;
    }
    
    for (View::Iterator iter = rootView->childIteratorBegin(); iter != rootView->childIteratorEnd(); iter++) {
      this->render(*iter);
    }
  }
}

