//
//  Button.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "Button.hpp"

namespace grumble {
    Button::Button() : View() {
        
    }

    Button::~Button() {
        
    }

    #pragma mark Setters

    void Button::setActiveColor(glm::vec4 activeColor) {
        _activeColor = activeColor;
    }

    void Button::setInactiveColor(glm::vec4 inactiveColor) {
        _inactiveColor = inactiveColor;
    }
}
