#include "Transform.hpp"
#include "../util/MathUtils.hpp"
#include "TransformOrigin.hpp"

namespace grumble {
Transform::Transform(const std::string_view &id, HMM_Vec2 position,
                     HMM_Vec2 size, TransformOrigin origin)
    : Object(id), _position(position), _origin(origin), _size(size) {}

Transform::~Transform() {}

#pragma mark Setters

void Transform::setPosition(HMM_Vec2 position) { _position = position; }

void Transform::setSize(HMM_Vec2 size) { _size = size; }

#pragma mark Getters

const HMM_Vec2 Transform::position() const { return _position; }

const HMM_Mat4 Transform::modelMatrix(float renderScale) const {
  HMM_Vec2 resultPosition = _position;
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

const HMM_Vec2 Transform::size() const { return _size; }

const std::string Transform::toString() const {
  return fmt::format("localPosition: {}, size: {}, origin: {}",
                     HMM_Vec2_toString(_position), HMM_Vec2_toString(size()),
                     TransformOrigin_toString(_origin));
}

} // namespace grumble
