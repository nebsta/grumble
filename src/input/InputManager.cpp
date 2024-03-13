#include "InputManager.hpp"
#include "InputCode.hpp"
#include <fmt/core.h>

namespace grumble {

InputManager::InputManager() : grumble::Object("input_manager") {}

InputManager::~InputManager() {}

void InputManager::clearTriggeredInputs() { _triggeredInputs.clear(); }

void InputManager::activateInput(InputCode code) {
  if (code == InputCode::Unknown || isInputActive(code)) {
    return;
  }

  logDebug("Activating input: {}", InputCode_to_string(code));
  _activeInputs.insert(code);
  _triggeredInputs.insert(code);
  logActiveInputs();
}

void InputManager::deactivateInput(InputCode code) {
  if (code == InputCode::Unknown || !isInputActive(code)) {
    return;
  }

  logDebug("Deactivating input {}", InputCode_to_string(code));
  _activeInputs.erase(code);
  logActiveInputs();
}

bool InputManager::isInputActive(InputCode code) const {
  return _activeInputs.count(code);
}

bool InputManager::isInputTriggered(InputCode code) const {
  return _triggeredInputs.count(code);
}

void InputManager::logActiveInputs() const {
  std::string output = "";
  std::set<InputCode>::iterator it;
  for (it = _activeInputs.begin(); it != _activeInputs.end(); it++) {
    auto inputKey = *it;

    output += fmt::format("{}, ", InputCode_to_string(inputKey));
  }
  logDebug("Current active inputs: {}", output);
}

void InputManager::mouseMoved(HMM_Vec2 pos) { _mousePosition = pos; }

HMM_Vec2 InputManager::mousePosition() const { return _mousePosition; }

LogCategory InputManager::logCategory() const { return LogCategory::input; }
} // namespace grumble
