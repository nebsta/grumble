#pragma once

#include "../core/Object.hpp"
#include "FrameStats.hpp"
#include "GridResolution.hpp"
#include <memory>

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

  void setFrameStatsVisble(bool visible);
  void toggleFrameStatsVisible();

  void setGridResolution(GridResolution resolution);

  void setFrameStats(FrameStats stats);

  const bool gridVisible() const;
  const bool instanceIdVisible() const;
  const GridResolution gridResolution() const;
  const bool debugMenuVisible() const;
  const bool frameStatsVisible() const;
  const FrameStats frameStats() const;

protected:
  LogCategory logCategory() const override;

private:
  bool _debugMenuVisible;

  bool _gridVisible;
  GridResolution _gridResolution;

  bool _frameStatsVisible;
  FrameStats _frameStats;

  bool _instanceIdVisible;
};
} // namespace grumble
