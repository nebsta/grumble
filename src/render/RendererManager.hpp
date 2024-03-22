//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.

#pragma once

#include "RendererManagerConfiguration.hpp"
#include <memory>

#include "../core/Camera.hpp"
#include "../core/Object.hpp"
#include "../debug/DebugState.hpp"
#include "../util/HandmadeMath.h"
#include "ViewInstance.hpp"

namespace grumble {
class RendererManager : public Object {
public:
  typedef std::shared_ptr<RendererManager> shared_ptr;

  RendererManager(RendererManagerConfiguration config);
  virtual ~RendererManager() = default;

  void setup(Camera::shared_ptr camera, DebugState::shared_ptr debugState);
  virtual void teardown() = 0;

  void prepareFrame(double t);
  virtual void updateInstanceBuffer(int instanceId, ViewInstance instance,
                                    double t) = 0;
  void drawFrame(double t);

  void setScreenSize(HMM_Vec2 size);

  const float renderScale() const;

private:
  RendererManagerConfiguration _configuration;
  float _renderScale;
  Camera::shared_ptr _camera;
  HMM_Mat4 _projectionMatrix;
  DebugState::shared_ptr _debugState;

protected:
  virtual void setup() = 0;

  LogCategory logCategory() const override;
  HMM_Vec2 cameraPos(double t) const;
  HMM_Mat4 viewMatrix(double t) const;
  HMM_Mat4 projectionViewMatrix(double t) const;
  const RendererManagerConfiguration configuration() const;

  virtual void prepareMainLayer(double t) = 0;

  virtual void drawMainLayer() = 0;
  virtual void drawDebugGrid(GridResolution resolution, double t) = 0;
  virtual void drawDebugStats(DebugState::shared_ptr debugState) = 0;
  virtual void drawDebugMenu(DebugState::shared_ptr debugState, double t) = 0;
  virtual void commitFrame() = 0;
};
} // namespace grumble
