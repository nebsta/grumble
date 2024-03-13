//
//  Transform.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Transform.hpp"

namespace grumble {
Transform::Transform(glm::vec2 position, glm::vec2 size, TransformOrigin origin)
    : _localPosition(position), _origin(origin), _parent(nullptr),
      _width(TransformDimension(DimensionSizing::Absolute, size.x)),
      _height(TransformDimension(DimensionSizing::Absolute, size.y)) {}

Transform::~Transform() { _parent = nullptr; }

#pragma mark Setters

void Transform::setLocalPosition(glm::vec2 localPosition) {
  _localPosition = localPosition;
}

void Transform::setRelativeWidth(float factor) {
  _width.update(DimensionSizing::Relative, factor);
}

void Transform::setRelativeHeight(float factor) {
  _height.update(DimensionSizing::Relative, factor);
}

void Transform::setWidth(float width) { _width.update(width); }

void Transform::setHeight(float height) { _height.update(height); }

void Transform::setSize(glm::vec2 size) {
  setWidth(size.x);
  setHeight(size.y);
}

void Transform::setParent(Transform::shared_ptr parent) { _parent = parent; }

#pragma mark Getters

glm::vec2 Transform::localPosition() const { return _localPosition; }

glm::vec2 Transform::screenPosition() const {
  glm::vec2 result = glm::vec2();
  if (_parent != nullptr) {
    result = _parent->screenPosition();
  }
  return result + _localPosition;
}

const bool Transform::hasParent() const { return _parent != nullptr; }

const HMM_Mat4 Transform::modelMatrix(float renderScale) const {
  glm::vec2 resultPosition = screenPosition();
  glm::vec2 resultSize = size() / renderScale;

  // applying offset based on origin
  if (_origin != TransformOrigin::TopLeft) {
    float halfWidth = size().x / 2.0f;
    float halfHeight = size().y / 2.0f;

    switch (_origin) {
    case TransformOrigin::Center:
      resultPosition += glm::vec2(-halfWidth, -halfHeight);
      break;
    case TransformOrigin::Top:
      resultPosition += glm::vec2(-halfWidth, 0);
      break;
    case TransformOrigin::TopRight:
      resultPosition += glm::vec2(-size().x, 0);
      break;
    case TransformOrigin::Left:
      resultPosition += glm::vec2(0, -halfHeight);
      break;
    case TransformOrigin::Right:
      resultPosition += glm::vec2(-size().x, -halfHeight);
      break;
    case TransformOrigin::BottomLeft:
      resultPosition += glm::vec2(0, -size().y);
      break;
    case TransformOrigin::Bottom:
      resultPosition += glm::vec2(-halfWidth, -size().y);
      break;
    case TransformOrigin::BottomRight:
      resultPosition += glm::vec2(-size().x, -size().y);
      break;
    default:
      break;
    }
  }

  HMM_Mat4 matrix = HMM_Translate({resultPosition.x, resultPosition.y, 0.0f});
  matrix = HMM_MulM4(matrix, HMM_Scale({resultSize.x, resultSize.y, 1.0f}));
  return matrix;
}

const glm::vec2 Transform::size() const {
  float width = 0.0f;
  float height = 0.0f;

  if (_width.sizing() == DimensionSizing::Absolute || _parent == nullptr) {
    width = _width.value();
  } else {
    float parentWidth = _parent->size().x;
    width = parentWidth * _width.value();
  }

  if (_height.sizing() == DimensionSizing::Absolute || _parent == nullptr) {
    height = _height.value();
  } else {
    float parentHeight = _parent->size().y;
    height = parentHeight * _height.value();
  }

  return {width, height};
}

bool Transform::containsLocalPoint(glm::vec2 point) const {
  return false;
  //    return point.x >= _localPosition.x && point.y >= _localPosition.y &&
  //    point.x <= _localPosition.x + _size.x && point.y <= _localPosition.y +
  //    _size.y;
}

bool Transform::containsScreenPoint(glm::vec2 point) const {
  return false;
  //    glm::vec2 sPos = screenPosition();
  //
  //    return point.x >= sPos.x && point.y >= sPos.y &&
  //    point.x <= sPos.x + _size.x && point.y <= sPos.y + _size.y;
}
} // namespace grumble
