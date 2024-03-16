#pragma once

#include "Object.hpp"
#include <vector>

namespace grumble {
class System : public Object {
public:
  typedef std::unique_ptr<System> unique_ptr;
  typedef std::vector<unique_ptr> vector;
  typedef vector::iterator iterator;

  System(std::string id);
  virtual ~System() = default;

  virtual void update(double dt) = 0;
};
} // namespace grumble
