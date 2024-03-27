#pragma once

#include "../core/Object.hpp"
#include "../util/HandmadeMath.h"
#include "TransformOrigin.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace grumble {
class Transform : public Object {
public:
  typedef std::unique_ptr<Transform> unique_ptr;
  typedef std::shared_ptr<Transform> shared_ptr;
  typedef std::weak_ptr<Transform> weak_ptr;

  Transform(const std::string_view &id, HMM_Vec2 position = {0, 0},
            HMM_Vec2 size = {10, 10},
            TransformOrigin origin = TransformOrigin::TopLeft);
  ~Transform();

  void setPosition(HMM_Vec2 position);
  void setSize(HMM_Vec2 size);

  const HMM_Vec2 position() const;
  const HMM_Vec2 size() const;
  const HMM_Mat4 modelMatrix(float renderScale) const;

  bool containsPoint(HMM_Vec2 point) const;

  const std::string toString() const override;

private:
  HMM_Vec2 _position;
  HMM_Vec2 _size;

  TransformOrigin _origin;
};
} // namespace grumble
