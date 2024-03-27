#pragma once

#include "View.hpp"

namespace grumble {
class ViewContainer : public View {
public:
  ViewContainer(const std::string &id);
  ~ViewContainer();

  void addView(View::unique_ptr view);

  void update(double dt) override;
  void pushBuffer(InstanceBufferCollection &collection, double t) override;

private:
  View::unique_vector _views;
};
} // namespace grumble
