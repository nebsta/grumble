//
//  Label.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "Label.hpp"

namespace grumble {
  Label::Label() : Label("") {
    
  }

  Label::Label(std::string text) :
    _text(text) {
    
  }
}
