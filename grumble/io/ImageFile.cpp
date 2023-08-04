//
//  ImageFile.cpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#include "ImageFile.hpp"

namespace grumble {
  ImageFile::ImageFile(int width, int height, int bytesPerRow, png_byte* data) :
    _width(width),
    _height(height),
    _bytesPerRow(bytesPerRow),
    _data(data) {
    
  }

  ImageFile::~ImageFile() {
    logInfo("Destroying image file data");
    delete _data;
  }

  const int ImageFile::width() const {
    return _width;
  }

  const int ImageFile::height() const {
    return _height;
  }


  const int ImageFile::bytesPerRow() const {
    return _bytesPerRow;
  }

  const png_byte* const ImageFile::data() const {
    return _data;
  }
}
