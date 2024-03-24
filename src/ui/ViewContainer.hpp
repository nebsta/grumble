#pragma once

#include "View.hpp"

namespace grumble {
class ViewContainer : public View {
public:
  ViewContainer();
  ~ViewContainer();

  void addView(View::unique_ptr view);

  void update(double dt) override;
  void updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                            double t) override;

private:
  View::unique_vector _views;
};
} // namespace grumble
