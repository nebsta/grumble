#include "ViewLayer.hpp"
#include "StackLayout.hpp"

namespace grumble {
ViewLayer::ViewLayer(const std::string &id) : StackLayout(id) {}

ViewLayer::~ViewLayer() {}

LogCategory ViewLayer::logCategory() const { return LogCategory::ui; }

} // namespace grumble
