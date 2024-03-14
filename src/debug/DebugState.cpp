#include "DebugState.hpp"
#include "GridResolution.hpp"

namespace grumble {
DebugState::DebugState() : _gridResolution(GridResolution::Small) {}

DebugState::~DebugState() {}

void DebugState::setGridVisible(bool visible) { _gridVisible = visible; }
void DebugState::toggleGridVisible() { _gridVisible = !_gridVisible; }

void DebugState::setInstanceIdVisible(bool visible) {
  _instanceIdVisible = visible;
}

void DebugState::toggleInstanceIdVisible() {
  _instanceIdVisible = !_instanceIdVisible;
}

void DebugState::setDebugMenuVisible(bool debugMenuVisible) {
  _debugMenuVisible = debugMenuVisible;
}

void DebugState::toggleDebugMenuVisible() {
  _debugMenuVisible = !_debugMenuVisible;
}

void DebugState::setGridResolution(GridResolution resolution) {
  _gridResolution = resolution;
}

const bool DebugState::gridVisible() const { return _gridVisible; }

const bool DebugState::instanceIdVisible() const { return _instanceIdVisible; }

const GridResolution DebugState::gridResolution() const {
  return _gridResolution;
}

const bool DebugState::debugMenuVisible() const { return _debugMenuVisible; }

LogCategory DebugState::logCategory() const { return LogCategory::core; }

} // namespace grumble
