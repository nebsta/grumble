#pragma once
#include "../core/Object.hpp"
#include "../util/HandmadeMath.h"
#include "FrameInput.hpp"
#include "InputCode.hpp"
#include <memory>
#include <set>

namespace grumble {
class InputManager : public grumble::Object {
public:
  typedef std::shared_ptr<InputManager> shared_ptr;

  InputManager();
  ~InputManager();

  FrameInput collect();
  void reset();

  bool isInputActive(InputCode code) const;
  bool isInputTriggered(InputCode code) const;

  HMM_Vec2 mousePosition() const;

protected:
  virtual void update() = 0;

  void scheduleTermination();
  void mouseMoved(HMM_Vec2 pos);

  void activateInput(InputCode code);
  void deactivateInput(InputCode code);

  LogCategory logCategory() const override;

private:
  bool _shouldTerminate;

  std::set<InputCode> _activeInputs;
  std::set<InputCode> _triggeredInputs;
  HMM_Vec2 _mousePosition;

  void logActiveInputs() const;
};
} // namespace grumble
