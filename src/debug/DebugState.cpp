#include "DebugState.hpp"
#include "GridResolution.hpp"

namespace grumble {
DebugState::DebugState() : _gridResolution(GridResolution::Small) {}

DebugState::~DebugState() {}

#pragma mark Setters

void DebugState::setGridVisible(bool visible) { _gridVisible = visible; }
void DebugState::toggleGridVisible() { setGridVisible(!_gridVisible); }

void DebugState::setInstanceIdVisible(bool visible) {
  _instanceIdVisible = visible;
}

void DebugState::toggleInstanceIdVisible() {
  setInstanceIdVisible(!_instanceIdVisible);
}

void DebugState::setDebugMenuVisible(bool debugMenuVisible) {
  _debugMenuVisible = debugMenuVisible;
}

void DebugState::toggleDebugMenuVisible() {
  setDebugMenuVisible(!_debugMenuVisible);
}

void DebugState::setFrameStatsVisble(bool visible) {
  _frameStatsVisible = visible;
}

void DebugState::toggleFrameStatsVisible() {
  setFrameStatsVisble(!_frameStatsVisible);
}

void DebugState::setGridResolution(GridResolution resolution) {
  _gridResolution = resolution;
}

void DebugState::setFrameStats(FrameStats stats) { _frameStats = stats; }

#pragma mark Getters

const bool DebugState::gridVisible() const { return _gridVisible; }

const bool DebugState::instanceIdVisible() const { return _instanceIdVisible; }

const GridResolution DebugState::gridResolution() const {
  return _gridResolution;
}

const bool DebugState::debugMenuVisible() const { return _debugMenuVisible; }

const bool DebugState::frameStatsVisible() const { return _frameStatsVisible; }

const FrameStats DebugState::frameStats() const { return _frameStats; }

LogCategory DebugState::logCategory() const { return LogCategory::core; }

} // namespace grumble
