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

  Renderer::Renderer(Mesh mesh, glm::vec4 tint) : Renderer(mesh, tint, RENDERER_DEFAULT_SHADER) {
    
  }

  Renderer::Renderer(Mesh mesh,
                     glm::vec4 tint,
                     std::string shader) : Renderer(mesh, tint, shader, RenderMethod::TringleStrip) {
    
  }

  Renderer::Renderer(Mesh mesh, glm::vec4 tint, std::string shader, RenderMethod renderMethod) {
    _mesh = mesh;
    _tint = tint;
    _shader = shader;
    _clipChildren = true;
    _renderMethod = renderMethod;
  }

  Renderer::~Renderer() {
  }

  void Renderer::render() {
    preDraw();
    draw();
    onPostDraw();
  }

  #pragma mark Clipping

  void Renderer::pushClippingRect() {
    
  }

  void Renderer::popClippingRect() {
    
  }

  #pragma mark Setters

  void Renderer::setModelviewMatrix(const glm::mat4& matrix) {
    _modelviewMatrix = matrix;
  }

  void Renderer::setTint(const glm::vec4& tint) {
    _tint = tint;
  }

  void Renderer::setClippingRect(const glm::vec4& clippingRect) {
    _clippingRect = clippingRect;
  }

  void Renderer::setClipChildren(const bool& clipChildren) {
    _clipChildren = clipChildren;
  }

  #pragma mark Virtual Methods

  void Renderer::preDraw() {
    
  }

  void Renderer::draw() {
    
  }

  void Renderer::onPostDraw() {
    
  }
}
