#include "InputManager.hpp"

namespace grumble {

InputManager::InputManager() : grumble::Object("input_mananger") {}

InputManager::~InputManager() {}

void InputManager::activateInput(InputCode code) {
  logDebug("Activating input {}", (int)code);
  _activeInputs.insert(code);
}

void InputManager::deactivateInput(InputCode code) {
  logDebug("Deactivating input {}", (int)code);
  _activeInputs.erase(code);
}

bool InputManager::isInputActive(InputCode code) const {
  return _activeInputs.count(code);
}

LogCategory InputManager::logCategory() { return LogCategory::input; }
} // namespace grumble
