//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <memory>

#include "Renderer.hpp"
#include "Sprite.hpp"

namespace grumble {
  class RendererManager {
  public:
    virtual ~RendererManager() = 0;
    
    virtual std::shared_ptr<Renderer> createViewRenderer() = 0;
    virtual std::shared_ptr<Renderer> createImageRenderer(const Sprite& sprite, const glm::vec4& tint) = 0;
  };
}
