//
//  AnimationCurves.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 24/04/17.
//  Copyright © 2017 The Caffeinated Coder. All rights reserved.
//

#include "AnimationCurves.hpp"

namespace grumble {
  glm::vec2 cubicBezier(float x1, float y1, float x2, float y2, float t) {
    float x = (3.0 * pow((1.0 - t),2) * t * x1) + (3.0 * (1.0-t) * pow(t,2) * x2) + (pow(t,3));
    float y = (3.0 * pow((1.0 - t),2) * t * y1) + (3.0 * (1.0-t) * pow(t,2) * y2) + (pow(t,3));
    return glm::vec2(x,y);
  }
}
