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
#include "../ui/ScreenManager.hpp"

#include "RenderMethod.hpp"
#include "Shapes.hpp"
#include "ShaderManager.hpp"

#define RENDERER_DEFAULT_COLOR COLOR_BLUE
#define RENDERER_DEFAULT_SHAPE grumble::Shapes.Square
#define RENDERER_DEFAULT_SHADER "ViewShader"

namespace grumble {
  class Renderer : public Object {
    
  public:
    Renderer();
    Renderer(glm::vec4 tint);
    Renderer(grumble::Mesh mesh, glm::vec4 tint);
    Renderer(grumble::Mesh mesh,
             glm::vec4 tint,
             std::string shader);
    Renderer(grumble::Mesh mesh,
             glm::vec4 tint,
             std::string shader,
             RenderMethod renderMethod);
    ~Renderer();
    
    void render();
    
    virtual void pushClippingRect();
    virtual void popClippingRect();
    
    void setModelviewMatrix(const glm::mat4& matrix);
    void setTint(const glm::vec4& tint);
    void setClipChildren(const bool& clipChildren);
    void setClippingRect(const glm::vec4& clippingRect);
    
  protected:
    std::string _shader;
    
    RenderMethod _renderMethod;
    bool _clipChildren;
    glm::vec4 _clippingRect;
    int _parentScissorRect[4];
    
    Mesh _mesh;
    glm::vec4 _tint;
    glm::mat4 _modelviewMatrix;
    glm::mat4 _projectionMatrix;
    
    virtual void preDraw();
    virtual void draw();
    virtual void onPostDraw();
  };
}
