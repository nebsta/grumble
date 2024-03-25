//
//  RendererManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#include "RendererManager.hpp"

namespace grumble {

RendererManager::RendererManager(RendererManagerConfiguration configuration,
                                 EditorView::unique_ptr editorView)
    : Object("renderer_manager"), _configuration(configuration),
      _editorView(std::move(editorView)) {}

void RendererManager::setup(Camera::shared_ptr camera,
                            DebugState::shared_ptr debugState) {
  _camera = camera;
  _debugState = debugState;
  setup();
}

void RendererManager::prepareFrame(double t) { prepareMainLayer(t); }

void RendererManager::drawFrame(double t) {
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

  if (_editorView->isActive()) {
    _editorView->draw();
  }

  commitFrame();
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
