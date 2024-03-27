#include "StackLayout.hpp"

namespace grumble {
StackLayout::StackLayout(const std::string &id) : View(id) {}

StackLayout::~StackLayout() {}

void StackLayout::addView(View::unique_ptr view) {
  _views.insert(_views.begin(), std::move(view));
}

void StackLayout::update(double dt) {
  for (auto &view : _views) {
    view->update(dt);
  }
}

void StackLayout::pushBuffer(InstanceBufferCollection &collection, double t) {
  for (auto &view : _views) {
    view->pushBuffer(collection, t);
  }
}

bool StackLayout::tryHandleTouch(HMM_Vec2 position) {
  for (auto &view : _views) {
    if (view->tryHandleTouch(position)) {
      return true;
    }
  }
  return false;
}

} // namespace grumble
