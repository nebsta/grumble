//
//  AnimationCurves.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 13/4/17.
//  Copyright © 2017 The Caffeinated Coder. All rights reserved.
//

#ifndef AnimationCurves_hpp
#define AnimationCurves_hpp

#include <glm/glm.hpp>

#define CURVE_LINEAR {0.25, 0.25, 0.75, 0.75}
#define CURVE_EASE_IN {0.48, 0.0, 0.83, 0.67}
#define CURVE_EASE_OUT {0.4, 0.66, 0.53, 1}

typedef struct BezierCurve {
    float x1; float y1; float x2; float y2;
} BezierCurve;

glm::vec2 cubicBezier(float x1, float y1, float x2, float y2, float t);

#endif /* AnimationCurves_hpp */

