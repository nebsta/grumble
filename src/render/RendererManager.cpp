//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"
#include "RendererManagerConfiguration.hpp"

namespace grumble {

RendererManager::RendererManager(RendererManagerConfiguration configuration)
    : _configuration(configuration) {
  setCameraPosition({0.0f, 0.0f});
}

void RendererManager::renderFrame(View::shared_ptr rootView) {
  this->renderView(rootView->transform(), rootView->renderer());

  if (!rootView->hasChildren()) {
    return;
  }

  View::iterator iter = rootView->childIteratorBegin();
  for (; iter != rootView->childIteratorEnd(); iter++) {
    auto view = *iter;
    switch (view->type()) {
    case ViewType::BaseType:
      this->renderView(view->transform(), view->renderer());
      break;
    case ViewType::ImageViewType:
      this->renderImageView(
          view->transform(),
          dynamic_pointer_cast<ImageRenderer>(view->renderer()));
      break;
    case ViewType::LabelViewType:
      this->renderLabel(view->transform(),
                        dynamic_pointer_cast<TextRenderer>(view->renderer()));
      break;
    }
  }
}

const float RendererManager::renderScale() const { return _renderScale; }

void RendererManager::setScreenSize(HMM_Vec2 size) {
  _projectionMatrix = HMM_Orthographic_LH_NO(0.0f, size.Width, size.Height,
                                             0.0f, -100.0f, 100.0f);
}

void RendererManager::setCameraPosition(HMM_Vec2 pos) {
  _viewMatrix = HMM_LookAt_LH({pos.X, pos.Y, -99.0f}, {pos.X, pos.Y, 0.0f},
                              {0.0f, 1.0f, 0.0f});
}

#pragma mark Protected Methods

LogCategory RendererManager::logCategory() const {
  return LogCategory::rendering;
}

HMM_Mat4 RendererManager::projectionViewMatrix() const {
  return HMM_MulM4(_projectionMatrix, _viewMatrix);
}

const RendererManagerConfiguration RendererManager::configuration() const {
  return _configuration;
}
} // namespace grumble
