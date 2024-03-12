#pragma once

#include "../util/HandmadeMath.h"
#include "Object.hpp"
#include <memory>

namespace grumble {
class Camera : public Object {
public:
  typedef std::shared_ptr<Camera> shared_ptr;

  Camera();
  ~Camera();

  void setPosition(HMM_Vec2 pos);

  HMM_Vec2 position() const;

private:
  HMM_Vec2 _pos;
};
} // namespace grumble
