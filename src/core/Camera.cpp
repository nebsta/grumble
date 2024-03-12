#include "Camera.hpp"

namespace grumble {

Camera::Camera() {}

Camera::~Camera() {}

void Camera::setPosition(HMM_Vec2 pos) { _pos = pos; }

HMM_Vec2 Camera::position() const { return _pos; }
} // namespace grumble
