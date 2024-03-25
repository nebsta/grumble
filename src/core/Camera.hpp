#pragma once

#include "../util/HandmadeMath.h"
#include "CameraRange.hpp"
#include "Object.hpp"
#include <memory>

namespace grumble {
class Camera : public Object {
public:
  typedef std::shared_ptr<Camera> shared_ptr;

  Camera();
  ~Camera();

  HMM_Vec2 velocity() const;

  HMM_Vec2 prevPosition() const;
  HMM_Vec2 lerpPosition(float t) const;
  HMM_Vec2 position() const;

  void update(double dt);
  void setVelocity(HMM_Vec2 velocity);
  void setCameraRange(CameraRange cameraRange);

private:
  HMM_Vec2 _velocity;
  HMM_Vec2 _prevPos;
  HMM_Vec2 _pos;
  CameraRange _cameraRange;
};
} // namespace grumble
