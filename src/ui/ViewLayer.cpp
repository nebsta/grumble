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
  for (auto &view : _views) {
    view->update(dt);
  }
}

void ViewLayer::pushBuffer(InstanceBufferCollection &collection, double t) {
  for (auto &view : _views) {
    view->pushBuffer(collection, t);
  }
}

bool ViewLayer::hasViews() const { return _views.size() != 0; }

LogCategory ViewLayer::logCategory() const { return LogCategory::ui; }

} // namespace grumble
