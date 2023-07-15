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

#include "../base/Object.hpp"
#include "../util/ColorConstants.hpp"
#include "../ui/ScreenManager.hpp"

#include "ShaderManager.hpp"

#define MAX_VERTICES 50

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#define RENDERER_DEFAULT_COLOR COLOR_BLUE
#define RENDERER_DEFAULT_SHAPE Square
#define RENDERER_DEFAULT_SHADER "ViewShader"
#define RENDERER_DEFAULT_PROJECTION glm::ortho(0.0f, ScreenManager::instance().screenWidth(), ScreenManager::instance().screenHeight(), 0.0f, 0.0f, 1000.0f)

namespace grumble {
  struct Vertex {
    glm::vec2 position;
    glm::vec2 textCoord;
  };

  struct Mesh {
    Vertex vertices[MAX_VERTICES];
    int vertexCount;
  };

  const Mesh Square = {
    {
      {glm::vec2(0.0f,1.0f),glm::vec2(0.0f,1.0f)},
      {glm::vec2(0.0f,0.0f),glm::vec2(0.0f,0.0f)},
      {glm::vec2(1.0f,1.0f),glm::vec2(1.0f,1.0f)},
      {glm::vec2(1.0f,0.0f),glm::vec2(1.0f,0.0f)}
    }, 4
  };


  class Renderer : public Object {
    
  public:
    Renderer();
    Renderer(const glm::vec4& tint);
    Renderer(const Mesh& mesh, const glm::vec4& tint);
    Renderer(const Mesh& mesh, const glm::vec4& tint, const std::string& shader);
    ~Renderer();
    
    void render();
    
    virtual void pushClippingRect();
    virtual void popClippingRect();
    
    void setModelviewMatrix(const glm::mat4& matrix);
    void setProjectionMatrix(const glm::mat4& matrix);
    void setTint(const glm::vec4& tint);
    void setClipChildren(const bool& clipChildren);
    void setClippingRect(const glm::vec4& clippingRect);
    
  protected:
    std::string _shader;
    
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
