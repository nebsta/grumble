#pragma once

#include "../core/Object.hpp"
#include <memory>

namespace grumble {
class EditorView : public Object {
public:
  typedef std::unique_ptr<EditorView> unique_ptr;

  virtual ~EditorView() = default;

  virtual bool isActive() const = 0;

  virtual void draw() = 0;
};
} // namespace grumble
