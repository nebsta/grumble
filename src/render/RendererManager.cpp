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
    drawDebugGrid(_debugState->gridResolution());
  }

  if (_debugState->frameStatsVisible()) {
    drawFrameStats(_debugState->currentFrameStats());
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

#pragma mark Protected Methods

HMM_Vec2 RendererManager::cameraPos() const { return _camera->position(); }

LogCategory RendererManager::logCategory() const {
  return LogCategory::rendering;
}

HMM_Mat4 RendererManager::projectionViewMatrix() const {
  return HMM_MulM4(_projectionMatrix, viewMatrix());
}

HMM_Mat4 RendererManager::viewMatrix() const {
  HMM_Vec2 cameraPos = _camera->position();
  return HMM_LookAt_LH({cameraPos.X, cameraPos.Y, -99.0f},
                       {cameraPos.X, cameraPos.Y, 0.0f}, {0.0f, 1.0f, 0.0f});
}

const RendererManagerConfiguration RendererManager::configuration() const {
  return _configuration;
}
} // namespace grumble
