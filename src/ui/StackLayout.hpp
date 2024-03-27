#pragma once

#include "View.hpp"

namespace grumble {
class StackLayout : public View {
public:
  StackLayout(const std::string &id);
  ~StackLayout();

  void addView(View::unique_ptr view);

  void update(double dt, FrameInput &inputx) override;
  void pushBuffer(InstanceBufferCollection &collection, double t) override;

  bool hasViews() const;

private:
  View::unique_vector _views;
};
} // namespace grumble
