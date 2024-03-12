#include "InputManager.hpp"
#include "InputCode.hpp"
#include <fmt/core.h>

namespace grumble {

InputManager::InputManager() : grumble::Object("input_mananger") {}

InputManager::~InputManager() {}

void InputManager::activateInput(InputCode code) {
  if (_activeInputs.count(code) == 1) {
    return;
  }

  logDebug("Activating input: {}", InputCode_to_string(code));
  _activeInputs.insert(code);
  logActiveInputs();
}

void InputManager::deactivateInput(InputCode code) {
  if (_activeInputs.count(code) == 0) {
    return;
  }

  logDebug("Deactivating input {}", InputCode_to_string(code));
  _activeInputs.erase(code);
  logActiveInputs();
}

bool InputManager::isInputActive(InputCode code) const {
  return _activeInputs.count(code);
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

LogCategory InputManager::logCategory() const { return LogCategory::input; }
} // namespace grumble
