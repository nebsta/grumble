//
//  TextRenderer.cpp
//  grumble
//
//  Created by Benjamin Wallis on 20/08/2023.
//

#include "TextRenderer.hpp"

namespace grumble {

TextRenderer::TextRenderer(std::string text, Font::shared_ptr font,
                           uint32_t instanceId)
    : Renderer(instanceId), _text(text), _font(font) {}

TextRenderer::~TextRenderer() {}

std::string TextRenderer::text() const { return _text; }

Font::shared_ptr TextRenderer::font() const { return _font; }
} // namespace grumble
