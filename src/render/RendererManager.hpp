//
//  Graphics.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 07/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <functional>
#include <memory>

#include "Renderer.hpp"
#include "RendererManagerConfiguration.hpp"
#include "TextRenderer.hpp"

#include "../core/Object.hpp"
#include "../render/ImageRenderer.hpp"
#include "../ui/View.hpp"

namespace grumble {
class RendererManager : public Object {
  typedef std::function<void(glm::vec2)> ScreenSizeUpdated;

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

  const float renderScale() const;
  const glm::vec2 screenSize() const;

  void setOnScreenSizeUpdated(ScreenSizeUpdated onScreenSizeUpdated);

private:
  RendererManagerConfiguration _configuration;
  float _renderScale;
  glm::vec2 _screenSize;
  ScreenSizeUpdated _onScreenSizeUpdated;

protected:
  glm::mat4 submitScreenSize(glm::vec2 size);

  LogCategory logCategory() override;
  const RendererManagerConfiguration configuration() const;
};
} // namespace grumble
