//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>

#include "Renderer.hpp"
#include "Sprite.hpp"

namespace grumble {
  class Graphics {
  public:
    static void Initialize();
    static Renderer* CreateViewRenderer(const glm::vec4& tint);
    static Renderer* CreateImageRenderer(const Sprite& sprite, const glm::vec4& tint);
    
  };
}
