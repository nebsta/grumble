//
//  TransformDimensions.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "TransformDimension.hpp"

namespace grumble {
  TransformDimension::TransformDimension(DimensionSizing sizing, float value) {
    _sizing = sizing;
    _value = value;
  }

  const DimensionSizing TransformDimension::sizing() const {
    return _sizing;
  }

   const float TransformDimension::value() const {
    return _value;
  }

  void TransformDimension::update(DimensionSizing sizing, float value) {
    _sizing = sizing;
    _value = value;
  }

  void TransformDimension::update(float value) {
    _value = value;
  }
}
