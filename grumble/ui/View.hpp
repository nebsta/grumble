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
#include <memory>

#include "Transform.hpp"
#include "ViewType.hpp"

#include "../input/Responder.hpp"
#include "../anim/ViewAnimator.hpp"
#include "../render/Renderer.hpp"

#include "../util/ColorConstants.hpp"
#include "../util/MathConstants.hpp"

namespace grumble {
  class View : public Object {
  public:
    typedef std::shared_ptr<View> shared_ptr;
    typedef std::vector<shared_ptr> vector;
    typedef vector::iterator iterator;
    
    View(glm::vec2 position = {0, 0},
         glm::vec2 size = {0, 0},
         TransformOrigin origin = TransformOrigin::TopLeft,
         Renderer::shared_ptr renderer = std::make_shared<Renderer>(),
         ViewType type = ViewType::BaseType);
    
    ~View();
    
    void update(const float& dt);
    
    void addChild(shared_ptr child);
    bool hasChildren() const;
    
    Transform::shared_ptr transform();
    Renderer::shared_ptr renderer();
    
    iterator childIteratorBegin();
    iterator childIteratorEnd();
    
    const ViewType type() const;
    
  protected:
    Transform::shared_ptr _transform;
    Renderer::shared_ptr _renderer;
    
  private:
    ViewType _type;
    vector _children;
  };
}
