//
//  Renderer.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Renderer.hpp"

namespace grumble {

Renderer::Renderer(Shape shape, RenderMethod renderMethod)
    : _tint(COLOR_WHITE), _renderMethod(renderMethod), _shape(shape) {}

Renderer::~Renderer() {}

#pragma mark Setters

void Renderer::setTint(const glm::vec4 &tint) { _tint = tint; }

#pragma mark Getters

const RenderMethod Renderer::renderMethod() const { return _renderMethod; }

const glm::vec4 Renderer::tint() const { return _tint; }

const Shape Renderer::shape() const { return _shape; }
} // namespace grumble
