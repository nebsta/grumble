//
//  Renderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include <vector>

#include "../core/Object.hpp"
#include "../util/ColorConstants.hpp"
#include "Shape.hpp"

#include "RenderMethod.hpp"

namespace grumble {
class Renderer : public Object {
public:
  typedef std::shared_ptr<Renderer> shared_ptr;
  typedef std::vector<shared_ptr>::iterator iterator;

  Renderer(Shape shape = SHAPE_SQUARE,
           RenderMethod renderMethod = RenderMethod::TriangleStrip);
  ~Renderer();

  void setTint(const glm::vec4 &tint);

  const RenderMethod renderMethod() const;
  const glm::vec4 tint() const;
  const Shape shape() const;

protected:
  RenderMethod _renderMethod;

  Shape _shape;
  glm::vec4 _tint;
};
} // namespace grumble
