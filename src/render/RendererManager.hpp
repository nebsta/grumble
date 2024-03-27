#pragma once

#include "../core/Camera.hpp"
#include "../core/Object.hpp"
#include "../debug/DebugState.hpp"
#include "../editor/EditorView.hpp"
#include "../util/HandmadeMath.h"
#include "InstanceBufferCollection.hpp"
#include "RendererManagerConfiguration.hpp"
#include <memory>

namespace grumble {
class RendererManager : public Object {
public:
  typedef std::shared_ptr<RendererManager> shared_ptr;

  RendererManager(RendererManagerConfiguration config,
                  EditorView::unique_ptr editorView);
  virtual ~RendererManager() = default;

  void setup(Camera::shared_ptr camera, DebugState::shared_ptr debugState);
  virtual void teardown() = 0;

  void prepareFrame(double t);
  void drawFrame(double t);
  void reset();

  void setScreenSize(HMM_Vec2 size);

  const float renderScale() const;
  InstanceBufferCollection &instanceBufferCollection();

private:
  RendererManagerConfiguration _configuration;

  float _renderScale;
  HMM_Mat4 _projectionMatrix;

  Camera::shared_ptr _camera;

  DebugState::shared_ptr _debugState;

  EditorView::unique_ptr _editorView;

protected:
  InstanceBufferCollection _instanceBuffers;

  const RendererManagerConfiguration configuration() const;

  virtual void setup() = 0;

  LogCategory logCategory() const override;
  HMM_Vec2 cameraPos(double t) const;
  HMM_Mat4 viewMatrix(double t) const;
  HMM_Mat4 projectionViewMatrix(double t) const;

  virtual void prepareMainLayer(double t) = 0;
  virtual void drawMainLayer() = 0;
  virtual void drawDebugGrid(GridResolution resolution, double t) = 0;
  virtual void drawDebugStats(DebugState::shared_ptr debugState) = 0;
  virtual void drawDebugMenu(DebugState::shared_ptr debugState, double t) = 0;
  virtual void commitFrame() = 0;
};
} // namespace grumble
