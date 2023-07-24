//
//  MathConstants.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#define VECTOR_EMPTY glm::vec2()
#define VECTOR_NEGATIVE glm::vec2(-1,-1)

#define RAND_FLOAT (static_cast<float>(rand()) / static_cast<float>(RAND_MAX))
#define RAND_RANGE(min,max) (min + (RAND_FLOAT * max))
