//
//  Transform.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Transform.hpp"
#include "../util/MathUtils.hpp"
#include "TransformOrigin.hpp"
#include <memory>

namespace grumble {
Transform::Transform(HMM_Vec2 position, HMM_Vec2 size, TransformOrigin origin)
    : _localPosition(position), _origin(origin),
      _parent(std::weak_ptr<Transform>()),
      _width(TransformDimension(DimensionSizing::Absolute, size.Width)),
      _height(TransformDimension(DimensionSizing::Absolute, size.Height)) {}

Transform::~Transform() {}

#pragma mark Setters

void Transform::setLocalPosition(HMM_Vec2 localPosition) {
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

void Transform::setSize(HMM_Vec2 size) {
  setWidth(size.Width);
  setHeight(size.Height);
}

void Transform::setParent(Transform::weak_ptr parent) { _parent = parent; }

#pragma mark Getters

HMM_Vec2 Transform::localPosition() const { return _localPosition; }

HMM_Vec2 Transform::screenPosition() const {
  HMM_Vec2 result = {0, 0};
  if (auto parent = _parent.lock()) {
    result = parent->screenPosition();
  }
  return result + _localPosition;
}

const bool Transform::hasParent() const { return !_parent.expired(); }

const HMM_Mat4 Transform::modelMatrix(float renderScale) const {
  HMM_Vec2 resultPosition = screenPosition();
  HMM_Vec2 resultSize = size() / renderScale;

  // applying offset based on origin
  if (_origin != TransformOrigin::TopLeft) {
    float halfWidth = size().X / 2.0f;
    float halfHeight = size().Y / 2.0f;

    switch (_origin) {
    case TransformOrigin::Center:
      resultPosition += {-halfWidth, -halfHeight};
      break;
    case TransformOrigin::Top:
      resultPosition += {-halfWidth, 0};
      break;
    case TransformOrigin::TopRight:
      resultPosition += {-size().X, 0};
      break;
    case TransformOrigin::Left:
      resultPosition += {0, -halfHeight};
      break;
    case TransformOrigin::Right:
      resultPosition += {-size().X, -halfHeight};
      break;
    case TransformOrigin::BottomLeft:
      resultPosition += {0, -size().Y};
      break;
    case TransformOrigin::Bottom:
      resultPosition += {-halfWidth, -size().Y};
      break;
    case TransformOrigin::BottomRight:
      resultPosition += {-size().X, -size().Y};
      break;
    default:
      break;
    }
  }

  HMM_Mat4 matrix = HMM_Translate({resultPosition.X, resultPosition.Y, 0.0f});
  matrix =
      HMM_MulM4(matrix, HMM_Scale({resultSize.Width, resultSize.Height, 1.0f}));
  return matrix;
}

const HMM_Vec2 Transform::size() const {
  float width = 0.0f;
  float height = 0.0f;

  if (_width.sizing() == DimensionSizing::Absolute || _parent.expired()) {
    width = _width.value();
  } else if (auto parent = _parent.lock()) {
    float parentWidth = parent->size().Width;
    width = parentWidth * _width.value();
  }

  if (_height.sizing() == DimensionSizing::Absolute || _parent.expired()) {
    height = _height.value();
  } else if (auto parent = _parent.lock()) {
    float parentHeight = parent->size().Height;
    height = parentHeight * _height.value();
  }

  return {width, height};
}

const std::string Transform::toString() const {
  return fmt::format("localPosition: {}, size: {}, origin: {}",
                     HMM_Vec2_toString(_localPosition),
                     HMM_Vec2_toString(size()),
                     TransformOrigin_toString(_origin));
}

bool Transform::containsLocalPoint(HMM_Vec2 point) const {
  return false;
  //    return point.x >= _localPosition.x && point.y >= _localPosition.y &&
  //    point.x <= _localPosition.x + _size.x && point.y <= _localPosition.y +
  //    _size.y;
}

bool Transform::containsScreenPoint(HMM_Vec2 point) const {
  return false;
  //    HMM_Vec2 sPos = screenPosition();
  //
  //    return point.x >= sPos.x && point.y >= sPos.y &&
  //    point.x <= sPos.x + _size.x && point.y <= sPos.y + _size.y;
}
} // namespace grumble
