//
//  Label.hpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#pragma once

#include "View.hpp"

#include "../font/Font.hpp"

#include "../render/TextRenderer.hpp"

namespace grumble {
class Label : public View {
public:
  Label(uint32_t instanceId, std::string text, Font::shared_ptr font,
        glm::vec2 position, TransformOrigin origin = TransformOrigin::TopLeft);
  ~Label();

private:
  std::string _text;
};
} // namespace grumble
