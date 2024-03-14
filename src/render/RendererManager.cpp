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
    : Object("renderer_manager"), _configuration(configuration) {
  setCameraPosition({0.0f, 0.0f});
}

void RendererManager::render(ViewLayer::iterator iter,
                             ViewLayer::iterator end) {
  prepareMainLayer();

  for (; iter != end; iter++) {
    ViewLayer::shared_ptr layer = (*iter);
    View::iterator viewIter = layer->viewIteratorBegin();
    for (; viewIter != layer->viewIteratorEnd(); viewIter++) {
      View::shared_ptr rootView = *viewIter;
      updateBufferNested(rootView);
    }
  }

  drawMainLayer();

  if (_debugState->gridVisible()) {
    drawDebugGrid(_debugState);
  }

  if (_debugState->debugMenuVisible()) {
    drawDebugMenu(_debugState);
  }

  commitFrame();
}

void RendererManager::updateBufferNested(View::shared_ptr view) {
  this->updateBuffer(view);

  if (!view->hasChildren()) {
    return;
  }

  View::iterator iter = view->childIteratorBegin();
  for (; iter != view->childIteratorEnd(); iter++) {
    View::shared_ptr view = (*iter);
    this->updateBuffer(view);
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

void RendererManager::setDebugState(DebugState::shared_ptr debugState) {
  _debugState = debugState;
}

#pragma mark Protected Methods

LogCategory RendererManager::logCategory() const {
  return LogCategory::rendering;
}

HMM_Mat4 RendererManager::projectionViewMatrix() const {
  return HMM_MulM4(_projectionMatrix, _viewMatrix);
}

HMM_Mat4 RendererManager::viewMatrix() const { return _viewMatrix; }

const RendererManagerConfiguration RendererManager::configuration() const {
  return _configuration;
}
} // namespace grumble
