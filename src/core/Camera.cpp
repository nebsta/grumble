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

  _pos.X = fmax(_pos.X, _cameraRange.left);
  _pos.X = fmin(_pos.X, _cameraRange.right);
  _pos.Y = fmax(_pos.Y, _cameraRange.top);
  _pos.Y = fmin(_pos.Y, _cameraRange.bottom);
}

HMM_Vec2 Camera::position() const { return _pos; }

HMM_Vec2 Camera::lerpPosition(float t) const { return lerp(_prevPos, _pos, t); }

HMM_Vec2 Camera::prevPosition() const { return _prevPos; }

void Camera::setCameraRange(CameraRange cameraRange) {
  _cameraRange = cameraRange;
}

} // namespace grumble
