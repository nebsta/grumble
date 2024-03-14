#include "ViewLayer.hpp"

namespace grumble {
ViewLayer::ViewLayer() {}

ViewLayer::~ViewLayer() {}

void ViewLayer::addView(View::shared_ptr view) {
  View::iterator pos = std::find(_views.begin(), _views.end(), view);
  if (pos != _views.end()) {
    return;
  }
  _views.push_back(view);
}

View::iterator ViewLayer::viewIteratorBegin() { return _views.begin(); }

View::iterator ViewLayer::viewIteratorEnd() { return _views.end(); }

void ViewLayer::update(double dt) {
  View::iterator iter = _views.begin();
  for (; iter != _views.end(); iter++) {
    View::shared_ptr view = *iter;
    view->update(dt);
  }
}

LogCategory ViewLayer::logCategory() const { return LogCategory::ui; }

} // namespace grumble
