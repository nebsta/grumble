//
//  Transform.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "../util/HandmadeMath.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../core/Object.hpp"

#include "TransformDimension.hpp"
#include "TransformOrigin.hpp"

namespace grumble {
class Transform : public Object {
public:
  typedef std::shared_ptr<Transform> shared_ptr;

  Transform(HMM_Vec2 position = {0, 0}, HMM_Vec2 size = {10, 10},
            TransformOrigin origin = TransformOrigin::TopLeft);
  ~Transform();

  void setLocalPosition(HMM_Vec2 localPosition);

  void setWidth(float width);
  void setHeight(float height);
  void setRelativeWidth(float factor);
  void setRelativeHeight(float factor);
  void setSize(HMM_Vec2 size);
  void setParent(Transform::shared_ptr parent);

  HMM_Vec2 localPosition() const;
  HMM_Vec2 screenPosition() const;
  const HMM_Vec2 size() const;
  const HMM_Mat4 modelMatrix(float renderScale) const;

  bool containsLocalPoint(HMM_Vec2 point) const;
  bool containsScreenPoint(HMM_Vec2 point) const;

private:
  HMM_Vec2 _localPosition;

  TransformDimension _width;
  TransformDimension _height;

  TransformOrigin _origin;

  Transform::shared_ptr _parent;
  const bool hasParent() const;

  float calculateDimensionSize(TransformDimension dimension, float parentSize);
};
} // namespace grumble
