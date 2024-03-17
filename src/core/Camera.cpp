#include "Camera.hpp"
#include "../util/MathUtils.hpp"

namespace grumble {

Camera::Camera()
    : Object("cameraMain"), _pos({0.0f, 0.0f}), _prevPos({0.0f, 0.0f}),
      _velocity({0.0f, 0.0f}) {}

Camera::~Camera() {}

void Camera::setVelocity(HMM_Vec2 velocity) { _velocity = velocity; }

void Camera::update(double dt) {
  _prevPos = _pos;

  if (HMM_Eq(_velocity, {0.0f, 0.0f})) {
    return;
  }

  float speed = HMM_Len(_velocity);
  float distance = speed * dt;
  HMM_Vec2 direction = HMM_Norm(_velocity);
  _pos += direction * distance;
}

HMM_Vec2 Camera::position() const { return _pos; }

HMM_Vec2 Camera::lerpPosition(float t) const { return lerp(_prevPos, _pos, t); }

HMM_Vec2 Camera::prevPosition() const { return _prevPos; }

} // namespace grumble
