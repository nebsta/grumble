//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"

namespace grumble {

RendererManager::RendererManager(RendererManagerConfiguration configuration)
    : Object("renderer_manager"), _configuration(configuration) {}

void RendererManager::setup(Camera::shared_ptr camera,
                            DebugState::shared_ptr debugState) {
  _camera = camera;
  _debugState = debugState;
  setup();
}

void RendererManager::render(ViewLayer::iterator iter, ViewLayer::iterator end,
                             double t) {
  prepareMainLayer(t);

  for (; iter != end; iter++) {
    ViewLayer::shared_ptr layer = (*iter);
    View::iterator viewIter = layer->viewIteratorBegin();
    for (; viewIter != layer->viewIteratorEnd(); viewIter++) {
      View::shared_ptr rootView = *viewIter;
      updateBufferNested(rootView, t);
    }
  }

  drawMainLayer();

  if (_debugState->gridVisible()) {
    drawDebugGrid(_debugState->gridResolution(), t);
  }

  if (_debugState->debugStatsVisible()) {
    drawDebugStats(_debugState);
  }

  if (_debugState->debugMenuVisible()) {
    drawDebugMenu(_debugState, t);
  }

  commitFrame();
}

void RendererManager::updateBufferNested(View::shared_ptr view, double t) {
  this->updateBuffer(view, t);

  if (!view->hasChildren()) {
    return;
  }

  View::iterator iter = view->childIteratorBegin();
  for (; iter != view->childIteratorEnd(); iter++) {
    View::shared_ptr view = (*iter);
    this->updateBuffer(view, t);
  }
}

const float RendererManager::renderScale() const { return _renderScale; }

void RendererManager::setScreenSize(HMM_Vec2 size) {
  _projectionMatrix = HMM_Orthographic_LH_NO(0.0f, size.Width, size.Height,
                                             0.0f, -100.0f, 100.0f);
}

#pragma mark Protected Methods

HMM_Vec2 RendererManager::cameraPos(double t) const {
  return _camera->lerpPosition(t);
}

LogCategory RendererManager::logCategory() const {
  return LogCategory::rendering;
}

HMM_Mat4 RendererManager::projectionViewMatrix(double t) const {
  return HMM_MulM4(_projectionMatrix, viewMatrix(t));
}

HMM_Mat4 RendererManager::viewMatrix(double t) const {
  HMM_Vec2 cameraPos = _camera->lerpPosition(t);
  return HMM_LookAt_LH({cameraPos.X, cameraPos.Y, -99.0f},
                       {cameraPos.X, cameraPos.Y, 0.0f}, {0.0f, 1.0f, 0.0f});
}

const RendererManagerConfiguration RendererManager::configuration() const {
  return _configuration;
}
} // namespace grumble
