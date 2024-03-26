#pragma once

#include "../anim/SpriteAnimator.hpp"
#include "../render/RendererManager.hpp"
#include "Transform.hpp"
#include "View.hpp"
#include <glm/glm.hpp>
#include <memory>
#include <vector>

namespace grumble {
class ImageView : public View {
public:
  typedef std::shared_ptr<ImageView> shared_ptr;
  typedef std::unique_ptr<ImageView> unique_ptr;
  typedef std::weak_ptr<ImageView> weak_ptr;

  typedef std::vector<shared_ptr> shared_vector;
  typedef std::vector<unique_ptr> unique_vector;
  typedef std::vector<weak_ptr> weak_vector;

  typedef shared_vector::iterator shared_iterator;
  typedef unique_vector::iterator unique_iterator;
  typedef weak_vector::iterator weak_iterator;

  ImageView(uint32_t instanceBufferId,
            const SpriteDefinition &sprite = EMPTY_SPRITE,
            HMM_Vec2 position = {0, 0}, HMM_Vec2 size = {0, 0},
            TransformOrigin origin = TransformOrigin::TopLeft);

  ~ImageView();

  void update(double dt) override;
  void updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                            double t) override;
  // setters
  void setPosition(HMM_Vec2 pos);
  void setSize(HMM_Vec2 size);
  void setSprite(const SpriteDefinition &sprite);

  // getters
  HMM_Vec2 position() const;
  HMM_Vec2 size() const;

private:
  SpriteAnimator::shared_ptr _spriteAnimator;
  Transform::unique_ptr _transform;

  SpriteDefinition _sprite;
  int _instanceBufferId;
};
} // namespace grumble
