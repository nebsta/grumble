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
#include <functional>
#include <typeinfo>

#include "Renderer.hpp"

#include "../core/Object.hpp"
#include "../ui/View.hpp"
#include "../ui/ImageView.hpp"

namespace grumble {
  class RendererManager: public Object {
    typedef std::function<void(glm::vec2)> ScreenSizeUpdated;
    
  public:
    typedef std::shared_ptr<RendererManager> shared_ptr;
    
    virtual ~RendererManager() = default;
    
    virtual void setup(float renderScale);
    virtual void setup() = 0;
    
    void renderAll(View::shared_ptr rootView);
    
    virtual void renderView(Transform::shared_ptr transform, Renderer::shared_ptr renderer) = 0;
    virtual void renderImageView(Transform::shared_ptr transform, ImageRenderer::shared_ptr renderer) = 0;
    
    const float renderScale() const;
    const glm::vec2 screenSize() const;
    
    void setOnScreenSizeUpdated(ScreenSizeUpdated onScreenSizeUpdated);
    
  private:
    float _renderScale;
    glm::vec2 _screenSize;
    ScreenSizeUpdated _onScreenSizeUpdated;
    
  protected:
    glm::mat4 submitScreenSize(glm::vec2 size);
    
    LogCategory logCategory() override;
  };
}
