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

const int DebugState::frameStatsIndex() const { return _frameStatsIndex; }

void DebugState::submitFrameStats(FrameStats stats) {
  int index = _frameStatsIndex + 1;
  if (index >= FRAME_STATS_WINDOW_SIZE) {
    index = 0;
  }

  _frameStatsHistory[index] = stats;
  _frameStatsIndex = index;
}

#pragma mark Getters

const bool DebugState::gridVisible() const { return _gridVisible; }

const bool DebugState::instanceIdVisible() const { return _instanceIdVisible; }

const GridResolution DebugState::gridResolution() const {
  return _gridResolution;
}

const bool DebugState::debugMenuVisible() const { return _debugMenuVisible; }

const bool DebugState::frameStatsVisible() const { return _frameStatsVisible; }

const FrameStats DebugState::currentFrameStats() const {
  return _frameStatsHistory[_frameStatsIndex];
}

const FrameStats *const DebugState::frameStatsHistory() const {
  return _frameStatsHistory;
}

LogCategory DebugState::logCategory() const { return LogCategory::core; }

} // namespace grumble
