//
//  Renderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Renderer.hpp"

namespace grumble {
  typedef std::vector<Renderer*>::iterator RendererIterator;

  Renderer::Renderer() : Renderer(RENDERER_DEFAULT_COLOR) {
    
  }

  Renderer::Renderer(glm::vec4 tint) : Renderer(grumble::Shapes::Square, tint) {
    
  }

  Renderer::Renderer(Mesh mesh, glm::vec4 tint) : Renderer(mesh, tint, RenderMethod::TriangleStrip) {
    
  }

  Renderer::Renderer(Mesh mesh, glm::vec4 tint, RenderMethod renderMethod) {
    _mesh = mesh;
    _tint = tint;
    _renderMethod = renderMethod;
  }

  Renderer::~Renderer() {
  }

  #pragma mark Setters

  void Renderer::setTint(const glm::vec4& tint) {
    _tint = tint;
  }

#pragma mark Getters

  const RenderMethod Renderer::renderMethod() const {
    return _renderMethod;
  }
}
