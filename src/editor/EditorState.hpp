#pragma once

#include "../core/Object.hpp"
#include <memory>

namespace grumble {
class EditorState : public Object {
public:
  typedef std::shared_ptr<EditorState> shared_ptr;

  EditorState();
  ~EditorState() = default;

  void setActive(bool active);
  void toggleActive();

  bool isActive() const;

private:
  bool _isActive;
};
} // namespace grumble
