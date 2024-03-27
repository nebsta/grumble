#pragma once

#include "../core/Object.hpp"
#include "../font/FontManager.hpp"
#include "../ui/ImageView.hpp"
#include <memory>

namespace grumble {
class ViewFactory : public Object {
public:
  typedef std::shared_ptr<ViewFactory> shared_ptr;

  ViewFactory(FontManager::shared_ptr fontManager);

  ImageView::unique_ptr
  createImageView(const std::string &id = "",
                  const SpriteDefinition &sprite = EMPTY_SPRITE,
                  HMM_Vec2 position = {0.0, 0.0}, HMM_Vec2 size = {0.0, 0.0},
                  TransformOrigin origin = TransformOrigin::TopLeft);

private:
  FontManager::shared_ptr _fontManager;
};
} // namespace grumble
