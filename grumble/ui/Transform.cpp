//
//  Transform.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Transform.hpp"

namespace grumble {
  Transform::Transform() : Transform(TRANSFORM_DEFAULT_POSITION) {
    
  }

  Transform::Transform(glm::vec2 position) : Transform(position, TRANSFORM_DEFAULT_SIZE, TransformOrigin::Center) {
    
  }

  Transform::Transform(glm::vec2 position, glm::vec2 size) : Transform(position, size, TransformOrigin::Center) {
    
  }

  Transform::Transform(glm::vec2 position,
                       glm::vec2 size,
                       TransformOrigin origin) {
    _localPosition = position;
    _size = size;
    _origin = origin;
    _constraint = TransformConstraint::None;
    _parent = nullptr;
  }

  Transform::~Transform() {
    _parent = nullptr;
  }

  #pragma mark Setters

  void Transform::setLocalPosition(glm::vec2 localPosition) {
    _localPosition = localPosition;
    _propertiesChanged = true;
  }

  void Transform::setSize(glm::vec2 size) {
    _size = size;
    _propertiesChanged = true;
  }

  void Transform::setConstraint(TransformConstraint constraint) {
    _constraint = constraint;
    _propertiesChanged = true;
  }

  void Transform::setParent(Transform* const parent) {
    _parent = parent;
    _propertiesChanged = true;
  }

  #pragma mark Getters

  glm::vec2 Transform::localPosition() const {
    return _localPosition;
  }

  glm::vec2 Transform::screenPosition() const {
    glm::vec2 result = glm::vec2();
//    if (_parent != nullptr) {
//      result = _parent->screenPosition();
//    }
    return result + _localPosition;
  }

  const bool Transform::hasParent() const {
    return _parent != nullptr;
  }

  const glm::mat4 Transform::modelMatrix() const {
    glm::mat4 matrix = glm::mat4(1.0f);
    glm::vec2 resultPosition = screenPosition();
    glm::vec2 resultSize = size();
    
    // applying offset based on origin
    if (_origin != TransformOrigin::Center) {
      float halfWidth = _size.x / 2.0f;
      float halfHeight = _size.y / 2.0f;
      
      switch (_origin) {
        case TransformOrigin::TopLeft: resultPosition += glm::vec2(halfWidth, halfHeight); break;
        case TransformOrigin::Top: resultPosition += glm::vec2(0, halfWidth); break;
        case TransformOrigin::TopRight: resultPosition += glm::vec2(-halfWidth, halfHeight); break;
        case TransformOrigin::Left: resultPosition += glm::vec2(halfWidth, 0); break;
        case TransformOrigin::Right: resultPosition += glm::vec2(-halfWidth, 0); break;
        case TransformOrigin::BottomLeft: resultPosition += glm::vec2(halfWidth, -halfHeight); break;
        case TransformOrigin::Bottom: resultPosition += glm::vec2(0, -halfHeight); break;
        case TransformOrigin::BottomRight: resultPosition += glm::vec2(-halfWidth, -halfHeight); break;
        default: break;
      }
    }
    
    matrix = glm::translate(matrix, glm::vec3(resultPosition.x,resultPosition.y,0.0f));
    
    // Applying view constraints
    if (_constraint != TransformConstraint::None && hasParent()) {
      glm::vec2 parentSize = _parent->size();
      if (_constraint == TransformConstraint::FillX) {
        resultSize.x = parentSize.x;
      } else if (_constraint == TransformConstraint::FillY) {
        resultSize.y = parentSize.y;
      } else {
        resultSize = parentSize;
      }
    }
    
    matrix = glm::scale(matrix, glm::vec3(resultSize.x,resultSize.y,1.0f));
    return matrix;
  }

  const glm::vec2 Transform::size() const {
    return _size;
  }

  bool Transform::containsLocalPoint(glm::vec2 point) const {
    return point.x >= _localPosition.x && point.y >= _localPosition.y &&
    point.x <= _localPosition.x + _size.x && point.y <= _localPosition.y + _size.y;
  }

  bool Transform::containsScreenPoint(glm::vec2 point) const {
    glm::vec2 sPos = screenPosition();
    
    return point.x >= sPos.x && point.y >= sPos.y &&
    point.x <= sPos.x + _size.x && point.y <= sPos.y + _size.y;
  }
}
