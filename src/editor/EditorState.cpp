
#include "EditorState.hpp"

namespace grumble {
EditorState::EditorState() : _isActive(false) {}

void EditorState::setActive(bool active) { _isActive = active; }

void EditorState::toggleActive() { setActive(!_isActive); }

bool EditorState::isActive() const { return _isActive; }
} // namespace grumble
