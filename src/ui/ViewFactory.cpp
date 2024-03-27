#include "ViewFactory.hpp"

namespace grumble {
ViewFactory::ViewFactory(FontManager::shared_ptr fontManager)
    : _fontManager(fontManager) {}

ImageView::unique_ptr
ViewFactory::createImageView(const std::string &id,
                             const SpriteDefinition &sprite, HMM_Vec2 position,
                             HMM_Vec2 size, TransformOrigin origin) {

  return std::make_unique<ImageView>(id, sprite, position, size, origin);
}

} // namespace grumble
