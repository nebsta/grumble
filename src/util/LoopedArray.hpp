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

  const Element *data() const;
  uint32_t currentIndex() const;
  Element operator[](uint32_t index) const;

private:
  uint32_t _currentIndex;
  std::array<Element, Size> _array;
};

template <class Element, size_t Size>
LoopedArray<Element, Size>::LoopedArray() : _currentIndex(-1) {}

template <class Element, size_t Size>
LoopedArray<Element, Size>::~LoopedArray() {}

template <class Element, size_t Size>
void LoopedArray<Element, Size>::push(Element element) {
  int nextIndex = _currentIndex + 1;
  if (nextIndex >= Size) {
    nextIndex = 0;
  }

  _array[nextIndex] = element;
  _currentIndex = nextIndex;
}

template <class Element, size_t Size>
const Element *LoopedArray<Element, Size>::data() const {
  return _array.data();
}

template <class Element, size_t Size>
uint32_t LoopedArray<Element, Size>::currentIndex() const {
  return fmax(_currentIndex, 0);
}

template <class Element, size_t Size>
Element LoopedArray<Element, Size>::operator[](uint32_t index) const {
  return _array[index];
}

} // namespace grumble
