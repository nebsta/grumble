#include "Camera.hpp"

namespace grumble {

Camera::Camera() {}

Camera::~Camera() {}

void Camera::setLocation(glm::vec2 location) { _location = location; }

glm::vec2 Camera::location() const { return _location; }
} // namespace grumble
