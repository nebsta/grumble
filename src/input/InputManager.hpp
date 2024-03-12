#pragma once
#include "../core/Object.hpp"
#include "InputCode.hpp"
#include <memory>
#include <set>

namespace grumble {
class InputManager : public grumble::Object {
public:
  typedef std::shared_ptr<InputManager> shared_ptr;

  InputManager();
  ~InputManager();

  void activateInput(InputCode code);
  void deactivateInput(InputCode code);

  bool isInputActive(InputCode code) const;

protected:
  LogCategory logCategory() const override;

private:
  std::set<InputCode> _activeInputs;

  void logActiveInputs() const;
};
} // namespace grumble
