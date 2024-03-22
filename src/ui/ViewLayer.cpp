#include "ViewLayer.hpp"

namespace grumble {
ViewLayer::ViewLayer() {}

ViewLayer::~ViewLayer() {}

void ViewLayer::addView(View::unique_ptr view) {
  if (hasViews()) {
    View::unique_iterator pos = std::find(_views.begin(), _views.end(), view);
    if (pos != _views.end()) {
      logWarn("Trying to add a view to a layer when it already exists");
      return;
    }
  }
  _views.push_back(std::move(view));
}

void ViewLayer::update(double dt) {
  View::unique_iterator iter = _views.begin();
  for (; iter != _views.end(); iter++) {
    (*iter)->update(dt);
  }
}

void ViewLayer::updateInstanceBuffer(
    RendererManager::shared_ptr rendererManager, double t) {
  View::unique_iterator viewIter = _views.begin();
  for (; viewIter != _views.end(); viewIter++) {
    (*viewIter)->updateInstanceBuffer(rendererManager, t);
  }
}

bool ViewLayer::hasViews() const { return false; }

LogCategory ViewLayer::logCategory() const { return LogCategory::ui; }

} // namespace grumble
