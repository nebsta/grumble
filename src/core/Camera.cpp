#include "Camera.hpp"

namespace grumble {

Camera::Camera()
    : Object("cameraMain"), _pos({0.0f, 0.0f}), _velocity({0.0f, 0.0f}) {}

Camera::~Camera() {}

void Camera::setVelocity(HMM_Vec2 velocity) { _velocity = velocity; }

void Camera::update(double dt) {
  if (HMM_Eq(_velocity, {0.0f, 0.0f})) {
    return;
  }

  float speed = HMM_Len(_velocity);
  float distance = speed * dt;
  HMM_Vec2 direction = HMM_Norm(_velocity);
  logDebug("dir: {}, {}. dt: {}. Speed: {}. Distance: {}", direction.X,
           direction.Y, dt, speed, distance);
  _pos += direction * distance;
}

HMM_Vec2 Camera::position() const { return _pos; }
} // namespace grumble
