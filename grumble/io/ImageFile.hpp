//
//  ImageFile.hpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#pragma once

#include <png.h>

#include "../core/Object.hpp"

namespace grumble {
  class ImageFile: public Object {
  public:
    ImageFile(float width, float height, png_byte* data);
    ~ImageFile();
    
    const float width() const;
    const float height() const;
    
    const png_byte* const data() const;
    
  private:
    float _width;
    float _height;
    
    png_byte* _data;
  };
}
