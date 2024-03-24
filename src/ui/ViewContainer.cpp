#include "ViewContainer.hpp"

namespace grumble {
ViewContainer::ViewContainer() {}

ViewContainer::~ViewContainer() {}

void ViewContainer::update(double dt) {
  auto iter = _views.begin();
  for (; iter != _views.end(); iter++) {
    (*iter)->update(dt);
  }
}

void ViewContainer::updateInstanceBuffer(
    RendererManager::shared_ptr rendererManager, double t) {
  auto iter = _views.begin();
  for (; iter != _views.end(); iter++) {
    (*iter)->updateInstanceBuffer(rendererManager, t);
  }
}

} // namespace grumble
