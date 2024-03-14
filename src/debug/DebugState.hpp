#pragma once

#include "../core/Object.hpp"
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

  void setGridResolution(GridResolution resolution);

  const bool gridVisible() const;
  const bool instanceIdVisible() const;
  const GridResolution gridResolution() const;
  const bool debugMenuVisible() const;

protected:
  LogCategory logCategory() const override;

private:
  bool _gridVisible;
  bool _instanceIdVisible;
  bool _debugMenuVisible;
  GridResolution _gridResolution;
};
} // namespace grumble
