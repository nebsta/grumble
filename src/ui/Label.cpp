//
//  Label.cpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#include "Label.hpp"

namespace grumble {
Label::Label(uint32_t instanceId, std::string text, Font::shared_ptr font,
             glm::vec2 position, TransformOrigin origin)
    : View(std::make_shared<TextRenderer>(text, font, instanceId), position,
           VECTOR_EMPTY, origin, ViewType::LabelViewType),
      _text(text) {}

Label::~Label() {}
} // namespace grumble
