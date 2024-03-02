//
//  ColorConstants.h
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>

#include "MathConstants.hpp"

#define COLOR_WHITE glm::vec4(1.0f,1.0f,1.0f,1.0f)
#define COLOR_BLACK glm::vec4(0.0f,0.0f,0.0f,1.0f)
#define COLOR_RED   glm::vec4(1.0f,0.0f,0.0f,1.0f)
#define COLOR_BLUE  glm::vec4(0.0f,0.0f,1.0f,1.0f)
#define COLOR_GREEN glm::vec4(0.0f,1.0f,0.0f,1.0f)
#define COLOR_CLEAR glm::vec4(1.0f,1.0f,1.0f,0.0f)
#define COLOR_RANDOM glm::vec4(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, 1.0f)
