//
//  Button.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "View.hpp"

namespace grumble {
  class Button : public View {
    
  public:
    Button();
    ~Button();
    
    void setActiveColor(glm::vec4 activeColor);
    void setInactiveColor(glm::vec4 inactiveColor);
    
  private:
    glm::vec4 _activeColor;
    glm::vec4 _inactiveColor;
  };
}
