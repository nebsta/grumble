//
//  Label.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "Label.hpp"

namespace grumble {
  Label::Label(std::string text,
               Font::shared_ptr font,
               glm::vec2 position,
               TransformOrigin origin) :
    View(position, VECTOR_EMPTY, origin, std::make_shared<Renderer>(), ViewType::LabelViewType),
    _text(text) {
    
  }

  Label::~Label() {
    
  }
}
