//
//  Renderer.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 8/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "../core/Object.hpp"
#include "../sprite/SpriteDefinition.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>

namespace grumble {
class Renderer : public Object {
public:
  typedef std::unique_ptr<Renderer> unique_ptr;
  typedef std::vector<unique_ptr>::iterator iterator;

  Renderer(uint32_t instanceId);
  ~Renderer();

  void setTint(const glm::vec4 &tint);
  void setSprite(const SpriteDefinition &sprite);

  const uint32_t instanceId() const;
  const glm::vec4 tint() const;
  const SpriteDefinition sprite() const;

private:
  SpriteDefinition _sprite;
  int _instanceId;

protected:
  glm::vec4 _tint;
};
} // namespace grumble
