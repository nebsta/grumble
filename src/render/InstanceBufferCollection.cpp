#include "InstanceBufferCollection.hpp"
#include "../util/Macros.hpp"
#include "ViewInstance.hpp"

#define STARTING_INDEX -1

namespace grumble {
InstanceBufferCollection::InstanceBufferCollection(const std::string &id)
    : Object(id), _currentIndex(STARTING_INDEX) {}

InstanceBufferCollection::~InstanceBufferCollection() {}

void InstanceBufferCollection::push(const ViewInstance &instance) {
  _currentIndex++;
  ASSERT(_currentIndex < MAX_INSTANCES,
         "Reached the maximum number of instances");
  _buffers[_currentIndex] = instance;
}

const ViewInstance *const InstanceBufferCollection::data() {
  return _buffers.data();
}

size_t InstanceBufferCollection::size() const {
  return (_currentIndex + 1) * sizeof(ViewInstance);
}

void InstanceBufferCollection::reset() { _currentIndex = STARTING_INDEX; }

} // namespace grumble
