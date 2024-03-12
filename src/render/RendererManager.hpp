//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <memory>

#include "Renderer.hpp"
#include "RendererManagerConfiguration.hpp"
#include "TextRenderer.hpp"

#include "../core/Object.hpp"
#include "../render/ImageRenderer.hpp"
#include "../ui/View.hpp"
#include "../util/HandmadeMath.h"

namespace grumble {
class RendererManager : public Object {
public:
  typedef std::shared_ptr<RendererManager> shared_ptr;

  RendererManager(RendererManagerConfiguration config);
  virtual ~RendererManager() = default;

  virtual void setup() = 0;
  virtual void teardown() = 0;

  void renderFrame(View::shared_ptr rootView);

  virtual void prepareFrame() = 0;
  virtual void renderView(Transform::shared_ptr transform,
                          Renderer::shared_ptr renderer) = 0;
  virtual void renderImageView(Transform::shared_ptr transform,
                               ImageRenderer::shared_ptr renderer) = 0;
  virtual void renderLabel(Transform::shared_ptr transform,
                           TextRenderer::shared_ptr renderer) = 0;
  virtual void commitFrame() = 0;

  void setScreenSize(HMM_Vec2 size);
  void setCameraPosition(HMM_Vec2 pos);

  const float renderScale() const;

private:
  RendererManagerConfiguration _configuration;
  float _renderScale;
  HMM_Mat4 _projectionMatrix;
  HMM_Mat4 _viewMatrix;

protected:
  LogCategory logCategory() const override;
  HMM_Mat4 projectionViewMatrix() const;
  const RendererManagerConfiguration configuration() const;
};
} // namespace grumble
