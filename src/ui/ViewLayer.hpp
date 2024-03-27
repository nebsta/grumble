#pragma once

#include "StackLayout.hpp"
#include "ViewLayerType.hpp"

namespace grumble {
class ViewLayer : public StackLayout {
public:
  typedef std::unique_ptr<ViewLayer> unique_ptr;
  typedef std::array<unique_ptr, MAX_VIEW_LAYERS> array;

  ViewLayer(const std::string &id);
  ~ViewLayer();

protected:
  LogCategory logCategory() const override;
};

} // namespace grumble
