//
//  ImageFile.hpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#pragma once

#include "../core/Object.hpp"

namespace grumble {
class ImageFile : public Object {
public:
  typedef std::unique_ptr<ImageFile> unique_ptr;

  ImageFile(int width, int height, int bytesPerRow,
            std::shared_ptr<unsigned char> data);

  const int width() const;
  const int height() const;
  const int bytesPerRow() const;

  std::shared_ptr<unsigned char> data() const;

private:
  int _width;
  int _height;
  int _bytesPerRow;

  std::shared_ptr<unsigned char> _data;
};
} // namespace grumble
