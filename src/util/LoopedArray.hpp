#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace grumble {

template <class Element, size_t Size> class LoopedArray {

public:
  LoopedArray();
  ~LoopedArray();

  void push(Element element);

  Element *data() const;
  uint32_t currentIndex() const;

private:
  uint32_t _currentIndex;
  std::array<Element, Size> _array;
};
} // namespace grumble
