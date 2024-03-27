#include "DebugState.hpp"
#include "FrameStats.hpp"
#include "GridResolution.hpp"
namespace grumble {
DebugState::DebugState()
    : _gridResolution(GridResolution::Small), _debugMenuVisible(false),
      _gridVisible(false), _frameStatsVisible(false),
      _instanceIdVisible(false) {}

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

void DebugState::setDebugStatsVisble(bool visible) {
  _frameStatsVisible = visible;
}

void DebugState::toggleDebugStatsVisible() {
  setDebugStatsVisble(!_frameStatsVisible);
}

void DebugState::setGridResolution(GridResolution resolution) {
  _gridResolution = resolution;
}

const int DebugState::frameStatsIndex() const {
  return _frameStatsHistory.currentIndex();
}

void DebugState::submitFrameStats(FrameStats stats) {
  _frameStatsHistory.push(stats);
}

#pragma mark Getters

const bool DebugState::gridVisible() const { return _gridVisible; }

const bool DebugState::instanceIdVisible() const { return _instanceIdVisible; }

const GridResolution DebugState::gridResolution() const {
  return _gridResolution;
}

const bool DebugState::debugMenuVisible() const { return _debugMenuVisible; }

const bool DebugState::debugStatsVisible() const { return _frameStatsVisible; }

const FrameStats *const DebugState::frameStatsHistory() const {
  return _frameStatsHistory.data();
}

const float DebugState::averageFrameTimeMs() const {
  float sum = 0.0f;
  for (int i = 0; i < FRAME_STATS_WINDOW_SIZE; i++) {
    sum += _frameStatsHistory[i].frameTimeMs;
  }
  return sum / FRAME_STATS_WINDOW_SIZE;
}

const float DebugState::averageUpdateTimeMs() const {
  float sum = 0.0f;
  for (int i = 0; i < FRAME_STATS_WINDOW_SIZE; i++) {
    sum += _frameStatsHistory[i].updateTimeMs;
  }
  return sum / FRAME_STATS_WINDOW_SIZE;
}

const float DebugState::averageRenderTimeMs() const {
  float sum = 0.0f;
  for (int i = 0; i < FRAME_STATS_WINDOW_SIZE; i++) {
    sum += _frameStatsHistory[i].renderTimeMs;
  }
  return sum / FRAME_STATS_WINDOW_SIZE;
}

const float DebugState::averageFrameLagMs() const {
  float sum = 0.0f;
  for (int i = 0; i < FRAME_STATS_WINDOW_SIZE; i++) {
    sum += _frameStatsHistory[i].frameLagMs;
  }
  return sum / FRAME_STATS_WINDOW_SIZE;
}

const float DebugState::averageFrameDelayMs() const {
  float sum = 0.0f;
  for (int i = 0; i < FRAME_STATS_WINDOW_SIZE; i++) {
    sum += _frameStatsHistory[i].frameDelayMs;
  }
  return sum / FRAME_STATS_WINDOW_SIZE;
}

const float DebugState::averageFPS() const {
  return 1000.0f / averageFrameTimeMs();
}

LogCategory DebugState::logCategory() const { return LogCategory::core; }

} // namespace grumble
