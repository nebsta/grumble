#pragma once

#include "Object.hpp"
#include <memory>

namespace grumble {
class Camera : public Object {
public:
  typedef std::shared_ptr<Camera> shared_ptr;

  Camera();
  ~Camera();

  void setLocation(glm::vec2 location);

  glm::vec2 location() const;

private:
  glm::vec2 _location;
};
} // namespace grumble
