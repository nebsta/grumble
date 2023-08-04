//
//  ImageFile.cpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#include "ImageFile.hpp"

namespace grumble {
  ImageFile::ImageFile(float width, float height, png_byte* data) :
    _width(width),
    _height(height),
    _data(data) {
    
  }

  ImageFile::~ImageFile() {
    logInfo("Destroying image file data");
    delete _data;
  }

  const float ImageFile::width() const {
    return _width;
  }

  const float ImageFile::height() const {
    return _height;
  }

  const png_byte* const ImageFile::data() const {
    return _data;
  }
}
