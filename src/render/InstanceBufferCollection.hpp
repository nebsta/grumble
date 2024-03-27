#pragma once

#include "../core/Object.hpp"
#include "ViewInstance.hpp"
#include <array>
#include <cstddef>

#define MAX_INSTANCES 50000

namespace grumble {
class InstanceBufferCollection : public Object {
public:
  InstanceBufferCollection(const std::string &id);
  ~InstanceBufferCollection();

  void push(const ViewInstance &instance);

  uint32_t count() const;
  size_t size() const;

  void reset();
  const ViewInstance *const data();

private:
  uint32_t _currentIndex;
  std::array<ViewInstance, MAX_INSTANCES> _buffers;
};
} // namespace grumble
