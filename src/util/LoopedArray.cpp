#include "LoopedArray.hpp"

namespace grumble {
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
Element *LoopedArray<Element, Size>::data() const {
  return _array.data();
}

template <class Element, size_t Size>
uint32_t LoopedArray<Element, Size>::currentIndex() const {
  return fmax(_currentIndex, 0);
}

} // namespace grumble
