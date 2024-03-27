#pragma once

#include "View.hpp"

namespace grumble {
class StackLayout : public View {
public:
  StackLayout(const std::string &id);
  ~StackLayout();

  void addView(View::unique_ptr view);

  void update(double dt) override;
  void pushBuffer(InstanceBufferCollection &collection, double t) override;
  bool tryHandleTouch(HMM_Vec2 position) override;

private:
  View::unique_vector _views;
};
} // namespace grumble
