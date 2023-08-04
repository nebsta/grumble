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
    typedef std::vector<ImageFile>::const_iterator Iterator;
    
  public:
    ImageFile(int width, int height, int bytesPerRow, png_byte* data);
    ~ImageFile();
    
    const int width() const;
    const int height() const;
    const int bytesPerRow() const;
    
    const png_byte* const data() const;
    
  private:
    int _width;
    int _height;
    int _bytesPerRow;
    
    png_byte* _data;
  };
}
