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

#include "../input/Responder.hpp"
#include "../anim/ViewAnimator.hpp"

#include "../util/ColorConstants.hpp"
#include "../util/MathConstants.hpp"

#define VIEW_DEFAULT_COLOR COLOR_WHITE
#define VIEW_DEFAULT_POSITION glm::vec2(0,0)
#define VIEW_DEFAULT_SIZE glm::vec2(10,10)

namespace grumble {
  class View : public Object {
  public:
    typedef std::vector<std::shared_ptr<View>> List;
    typedef List::iterator Iterator;
    
    View(glm::vec2 position, glm::vec2 size);
    
    ~View();
    
    void update(const float& dt);
    
    void addChild(std::shared_ptr<View> child);
    bool hasChildren() const;
    
    Transform& transform();
    
    Iterator childIteratorBegin();
    Iterator childIteratorEnd();
    
  protected:
    Transform _transform;
    
  private:
    List _children;
  };
}
