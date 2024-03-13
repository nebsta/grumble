//
//  ViewFactory.hpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#pragma once

#include <memory>

#include "../core/Object.hpp"

#include "../ui/ImageView.hpp"
#include "../ui/Label.hpp"
#include "../ui/View.hpp"

#include "../font/FontManager.hpp"

#include "../sprite/Sprite.hpp"

#include "../render/RendererManager.hpp"

namespace grumble {
class ViewFactory : public Object {
public:
  typedef std::shared_ptr<ViewFactory> shared_ptr;

  ViewFactory(FontManager::shared_ptr fontManager);

  View::shared_ptr
  createView(glm::vec2 position = VECTOR_EMPTY, glm::vec2 size = {0.0, 0.0},
             TransformOrigin origin = TransformOrigin::TopLeft);
  ImageView::shared_ptr
  createImageView(Sprite::shared_ptr sprite, glm::vec2 position = VECTOR_EMPTY,
                  glm::vec2 size = {10.0f, 10.0},
                  TransformOrigin origin = TransformOrigin::TopLeft);

  Label::shared_ptr
  createLabel(std::string text = "", std::shared_ptr<Font> font = nullptr,
              glm::vec2 position = VECTOR_EMPTY,
              TransformOrigin origin = TransformOrigin::TopLeft);

private:
  FontManager::shared_ptr _fontManager;
  uint32_t _runningInstanceId;

  uint32_t generateInstanceId();
};
} // namespace grumble
