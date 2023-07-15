//
//  View.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <glm/glm.hpp>
#include <vector>

#include "Transform.hpp"
#include "ScreenManager.hpp"

#include "../input/Responder.hpp"

#include "../anim/ViewAnimator.hpp"

#include "../render/Renderer.hpp"
#include "../render/Graphics.hpp"

#include "../util/ColorConstants.hpp"
#include "../util/MathConstants.hpp"

#define VIEW_DEFAULT_COLOR COLOR_WHITE
#define VIEW_DEFAULT_POSITION glm::vec2(0,0)
#define VIEW_DEFAULT_SIZE glm::vec2(10,10)

namespace grumble {
  class View : public Object {
    
  public:
    View();
    View(const glm::vec2& position);
    View(const glm::vec2& position, const glm::vec2& size);
    View(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    View(const glm::vec2& position, const glm::vec2& size, Renderer* renderer);
    
    ~View();
    
    void render();
    void update(const float& dt);
    
    void setViewConstraint(TransformConstraint constraint);
    
    void touchBegin(Touch touch);
    void touchEnd(Touch touch);
    
    void setOnTouchBegin(std::function<void(Touch)> callback);
    void setOnTouchEnd(std::function<void(Touch)> callback);
    
    void addChild(View* const child);
    void removeChild(View* const view);
    bool hasChildren() const;
    
    Renderer* const renderer();
    Transform& transform();
    Responder& responder();
    ViewAnimator& animator();
    
  protected:
    std::unique_ptr<Renderer> _renderer;
    Transform _transform;
    ViewAnimator _animator;
    Responder _responder;
    
    void consumeTransformChanges();
    void refreshRendererMatrix();
    void refreshRendererClip();
    
  private:
    std::vector<View*> _children;
    
    const ScreenManager& _screenManager;
  };
}
