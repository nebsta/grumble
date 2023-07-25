//
//  TransformDimensions.hpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#pragma once

#include "DimensionSizing.hpp"

namespace grumble {
  class TransformDimension {
  public:
    TransformDimension(DimensionSizing sizing = DimensionSizing::Absolute, float value = 0.0f);
    
    const DimensionSizing sizing() const;
    const float value() const;
    
    void update(DimensionSizing sizing, float value);
    void update(float value);
    
  private:
    DimensionSizing _sizing;
    
    float _value;
  };
}
