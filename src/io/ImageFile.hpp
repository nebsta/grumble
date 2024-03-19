//
//  ImageFile.hpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#pragma once

#include "../core/Object.hpp"
#include <memory>
#include <string_view>

namespace grumble {
class ImageFile : public Object {
public:
  typedef std::unique_ptr<ImageFile> unique_ptr;
  typedef std::weak_ptr<ImageFile> weak_ptr;
  typedef std::shared_ptr<ImageFile> shared_ptr;

  ImageFile(std::string_view name, int width, int height, int bytesPerRow,
            std::unique_ptr<unsigned char> data);

  std::string_view name() const;
  const int width() const;
  const int height() const;
  const int bytesPerRow() const;

  std::weak_ptr<unsigned char> data() const;

  const std::string toString() const override;

private:
  std::string_view _name;
  int _width;
  int _height;
  int _bytesPerRow;

  std::shared_ptr<unsigned char> _data;
};
} // namespace grumble
