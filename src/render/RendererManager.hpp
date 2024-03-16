//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include "RendererManagerConfiguration.hpp"
#include <memory>

#include "../core/Camera.hpp"
#include "../core/Object.hpp"
#include "../debug/DebugState.hpp"
#include "../ui/View.hpp"
#include "../ui/ViewLayer.hpp"
#include "../util/HandmadeMath.h"

namespace grumble {
class RendererManager : public Object {
public:
  typedef std::shared_ptr<RendererManager> shared_ptr;

  RendererManager(RendererManagerConfiguration config);
  virtual ~RendererManager() = default;

  void setup(Camera::shared_ptr camera, DebugState::shared_ptr debugState);
  virtual void teardown() = 0;

  void render(ViewLayer::iterator iter, ViewLayer::iterator end);

  virtual void updateBufferNested(View::shared_ptr view);

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
  HMM_Vec2 cameraPos() const;
  HMM_Mat4 viewMatrix() const;
  HMM_Mat4 projectionViewMatrix() const;
  const RendererManagerConfiguration configuration() const;

  virtual void prepareMainLayer() = 0;
  virtual void updateBuffer(View::shared_ptr view) = 0;
  virtual void drawMainLayer() = 0;
  virtual void drawDebugGrid(DebugState::shared_ptr debugState) = 0;
  virtual void drawDebugMenu(DebugState::shared_ptr debugState) = 0;
  virtual void commitFrame() = 0;
};
} // namespace grumble
