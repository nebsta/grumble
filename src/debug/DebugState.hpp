#pragma once

#include "../core/Object.hpp"
#include "FrameStats.hpp"
#include "GridResolution.hpp"
#include <memory>
#include <queue>

#define FRAME_STATS_WINDOW_SIZE 200

namespace grumble {
class DebugState : public Object {
public:
  typedef std::shared_ptr<DebugState> shared_ptr;

  DebugState();
  ~DebugState();

  void setGridVisible(bool visible);
  void toggleGridVisible();

  void setInstanceIdVisible(bool visible);
  void toggleInstanceIdVisible();

  void setDebugMenuVisible(bool visible);
  void toggleDebugMenuVisible();

  void setDebugStatsVisble(bool visible);
  void toggleDebugStatsVisible();

  void setGridResolution(GridResolution resolution);

  void submitFrameStats(FrameStats stats);

  const bool gridVisible() const;
  const bool instanceIdVisible() const;
  const GridResolution gridResolution() const;
  const bool debugMenuVisible() const;
  const bool debugStatsVisible() const;

  const float averageFrameTime() const;
  const float averageFPS() const;

  const int frameStatsIndex() const;
  const FrameStats currentFrameStats() const;
  const FrameStats *const frameStatsHistory() const;

protected:
  LogCategory logCategory() const override;

private:
  int _frameStatsIndex;
  FrameStats _frameStatsHistory[FRAME_STATS_WINDOW_SIZE];

  bool _debugMenuVisible;

  bool _gridVisible;
  GridResolution _gridResolution;

  bool _frameStatsVisible;

  bool _instanceIdVisible;
};
} // namespace grumble
