//
//  Renderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/glm.hpp>

#include <stdio.h>
#include <vector>

#include "../core/Object.hpp"
#include "../util/ColorConstants.hpp"

#include "RenderMethod.hpp"
#include "ShaderManager.hpp"

#define RENDERER_DEFAULT_COLOR COLOR_BLUE
#define RENDERER_DEFAULT_SHAPE grumble::Shapes.Square
#define RENDERER_DEFAULT_SHADER "ViewShader"

namespace grumble {
  class Renderer : public Object {
    
  public:
    Renderer();
    Renderer(glm::vec4 tint);
    Renderer(glm::vec4 tint, RenderMethod renderMethod);
    ~Renderer();
    
    void render();
    
    void setTint(const glm::vec4& tint);
    
    const RenderMethod renderMethod() const;
    const glm::vec4 tint() const;
    
  protected:
    RenderMethod _renderMethod;
    
    glm::vec4 _tint;
  };
}
