#include "DebugState.hpp"

namespace grumble {
DebugState::DebugState() {}

DebugState::~DebugState() {}

void DebugState::setGridVisible(bool visible) { _gridVisible = visible; }
void DebugState::toggleGridVisible() { _gridVisible = !_gridVisible; }

void DebugState::setInstanceIdVisible(bool visible) {
  _instanceIdVisible = visible;
}

void DebugState::toggleInstanceIdVisible() {
  _instanceIdVisible = !_instanceIdVisible;
}

const bool DebugState::gridVisible() const { return _gridVisible; }
const bool DebugState::instanceIdVisible() const { return _instanceIdVisible; }

} // namespace grumble
