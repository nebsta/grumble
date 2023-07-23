//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#import <stdio.h>
#import <memory>

#import "Renderer.hpp"
#import "Sprite.hpp"
#import "../ui/View.hpp"

namespace grumble {
  class RendererManager {
  public:
    virtual ~RendererManager() = default;
    
    void renderAll(std::shared_ptr<View> rootView);
    
    virtual void render(std::shared_ptr<View> view) = 0;
  };
}
