#include "StackLayout.hpp"

namespace grumble {
StackLayout::StackLayout(const std::string &id) : View(id) {}

StackLayout::~StackLayout() {}

void StackLayout::addView(View::unique_ptr view) {
  _views.insert(_views.begin(), std::move(view));
}

void StackLayout::update(double dt, FrameInput &input) {
  for (auto &view : _views) {
    view->update(dt, input);
  }
}

void StackLayout::pushBuffer(InstanceBufferCollection &collection, double t) {
  for (auto &view : _views) {
    view->pushBuffer(collection, t);
  }
}

bool StackLayout::hasViews() const { return _views.size() != 0; }

} // namespace grumble
