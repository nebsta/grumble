#include "DebugState.hpp"

namespace grumble {
DebugState::DebugState() {}

DebugState::~DebugState() {}

void DebugState::setGridVisible(bool visible) { _gridVisible = visible; }
void DebugState::setInstanceIdVisible(bool visible) {
  _instanceIdVisible = visible;
}

const bool DebugState::gridVisible() const { return _gridVisible; }
const bool DebugState::instanceIdVisible() const { return _instanceIdVisible; }

} // namespace grumble
