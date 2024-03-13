#pragma once

#include <memory>
namespace grumble {
class DebugState {
public:
  typedef std::shared_ptr<DebugState> shared_ptr;

  DebugState();
  ~DebugState();

  void setGridVisible(bool visible);
  void setInstanceIdVisible(bool visible);

  const bool gridVisible() const;
  const bool instanceIdVisible() const;

private:
  bool _gridVisible;
  bool _instanceIdVisible;
};
} // namespace grumble
