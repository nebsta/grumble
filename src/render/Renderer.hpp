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

namespace grumble {
class Renderer : public Object {
public:
  typedef std::shared_ptr<Renderer> shared_ptr;
  typedef std::vector<shared_ptr>::iterator iterator;

  Renderer(uint32_t instanceId);
  ~Renderer();

  void setTint(const glm::vec4 &tint);

  const uint32_t instanceId() const;
  const glm::vec4 tint() const;

private:
  int _instanceId;

protected:
  glm::vec4 _tint;
};
} // namespace grumble
