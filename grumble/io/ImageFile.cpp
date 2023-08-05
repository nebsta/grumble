//
//  ImageFile.cpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#include "ImageFile.hpp"

namespace grumble {
  ImageFile::ImageFile(int width, int height, int bytesPerRow, std::shared_ptr<unsigned char> data) :
    _width(width),
    _height(height),
    _bytesPerRow(bytesPerRow),
    _data(data) {
    
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

  std::shared_ptr<unsigned char> ImageFile::data() const {
    return _data;
  }
}
