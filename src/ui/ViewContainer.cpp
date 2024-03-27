#include "ViewContainer.hpp"
#include "View.hpp"

namespace grumble {
ViewContainer::ViewContainer(const std::string &id) : View(id) {}

ViewContainer::~ViewContainer() {}

void ViewContainer::update(double dt) {
  for (auto &view : _views) {
    view->update(dt);
  }
}

void ViewContainer::pushBuffer(InstanceBufferCollection &collection, double t) {
  for (auto &view : _views) {
    view->pushBuffer(collection, t);
  }
}

} // namespace grumble
