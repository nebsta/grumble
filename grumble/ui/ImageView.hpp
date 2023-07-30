//
//  ImageView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>

#include "View.hpp"

#include "../sprite/Sprite.hpp"

#include "../util/MathConstants.hpp"

#define IMAGEVIEW_DEFAULT_POSITION VECTOR_EMPTY
#define IMAGEVIEW_DEFAULT_COLOR COLOR_WHITE

namespace grumble {
  class ImageView : public View {
    
  public:
    ImageView(std::shared_ptr<Sprite> sprite = nullptr,
              glm::vec2 position = VECTOR_EMPTY,
              glm::vec2 size = glm::vec2(10,10),
              glm::vec4 tint = COLOR_WHITE);
    ~ImageView();
    
    void setSprite(Sprite sprite);
  private:
    std::shared_ptr<Sprite> _sprite;
  };
}
