//
//  ImageFile.cpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#include "ImageFile.hpp"
#include <string_view>

namespace grumble {
ImageFile::ImageFile(std::string_view name, int width, int height,
                     int bytesPerRow, std::unique_ptr<unsigned char> data)
    : _name(name), _width(width), _height(height), _bytesPerRow(bytesPerRow),
      _data(std::move(data)), Object(name) {}

std::string_view ImageFile::name() const { return _name; }

const int ImageFile::width() const { return _width; }

const int ImageFile::height() const { return _height; }

const int ImageFile::bytesPerRow() const { return _bytesPerRow; }

std::weak_ptr<unsigned char> ImageFile::data() const { return _data; }

const std::string ImageFile::toString() const {
  return fmt::format("id: {}, width: {}, height: {}, btyesPerRow: {}", _id,
                     _width, _height, _bytesPerRow);
}
} // namespace grumble
