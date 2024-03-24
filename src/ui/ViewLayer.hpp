#pragma once

#include "../core/Object.hpp"
#include "../render/RendererManager.hpp"
#include "../ui/ImageView.hpp"
#include "ViewLayerType.hpp"
#include <memory>

namespace grumble {
class ViewLayer : public Object {
public:
  typedef std::unique_ptr<ViewLayer> unique_ptr;
  typedef std::array<unique_ptr, MAX_VIEW_LAYERS> array;
  typedef array::iterator iterator;

  ViewLayer();
  ~ViewLayer();

  void addView(ImageView::unique_ptr view);

  void update(double dt);
  void updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                            double t);

  bool hasViews() const;

protected:
  LogCategory logCategory() const override;

private:
  ImageView::unique_vector _views;
};

} // namespace grumble
