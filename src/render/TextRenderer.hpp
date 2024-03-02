//
//  TextRenderer.hpp
//  grumble
//
//  Created by Benjamin Wallis on 20/08/2023.
//

#pragma once

#include "../render/Renderer.hpp"
#include "../font/Font.hpp"

namespace grumble {
  class TextRenderer: public Renderer {
  public:
    typedef std::shared_ptr<TextRenderer> shared_ptr;
    
    TextRenderer(std::string text,
                 Font::shared_ptr font,
                 RenderMethod renderMethod = RenderMethod::TriangleStrip);
    ~TextRenderer();
    
    std::string text() const;
    Font::shared_ptr font() const;
    
  private:
    Font::shared_ptr _font;
    std::string _text;
  };
}