//
//  Transform.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#define TRANSFORM_DEFAULT_POSITION glm::vec2(0,0)
#define TRANSFORM_DEFAULT_SIZE glm::vec2(10,10)

#include <vector>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../base/Object.hpp"
#include "ScreenManager.hpp"

namespace grumble {
  typedef enum TransformConstraint {
    TransformConstraint_None = 0,
    TransformConstraint_FillX = -1,
    TransformConstraint_FillY = -2,
    TransformConstraint_FillXY = -3
  } TransformConstraint;

  class Transform : public Object {
  public:
    Transform();
    Transform(glm::vec2 position);
    Transform(glm::vec2 position, glm::vec2 size);
    ~Transform();
    
    void setLocalPosition(glm::vec2 localPosition);
    void setSize(glm::vec2 size);
    void setConstraint(TransformConstraint constraint);
    void setParent(Transform* const parent);
    
    glm::vec2 localPosition() const;
    glm::vec2 screenPosition() const;
    const glm::vec2 size() const;
    const glm::mat4 matrix() const;
    const glm::vec4 rect() const;
    const bool consumePropertyChanges();
    
    bool containsLocalPoint(glm::vec2 point) const;
    bool containsScreenPoint(glm::vec2 point) const;
    
  private:
    glm::vec2 _localPosition;
    glm::vec2 _size;
    bool _propertiesChanged;
    
    TransformConstraint _constraint;
    Transform *_parent;
    const bool hasParent() const;
  };
}
