#pragma once

#include "../anim/SpriteAnimator.hpp"
#include "../render/Renderer.hpp"
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

  ImageView(uint32_t instanceId, HMM_Vec2 position = {0, 0},
            HMM_Vec2 size = {0, 0},
            TransformOrigin origin = TransformOrigin::TopLeft);

  ImageView(Renderer::unique_ptr renderer, HMM_Vec2 position = {0, 0},
            HMM_Vec2 size = {0, 0},
            TransformOrigin origin = TransformOrigin::TopLeft);

  ~ImageView();

  void update(double dt) override;
  void updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                            double t) override;

  // children handling
  void setParent(std::weak_ptr<Transform> parent);
  void addChild(unique_ptr child);
  bool hasChildren() const;

  // setters
  void setPosition(HMM_Vec2 pos);
  void setSize(HMM_Vec2 size);
  void setSprite(SpriteDefinition sprite);
  SpriteAnimator::shared_ptr spriteAnimator;

private:
  Transform::shared_ptr _transform;
  Renderer::unique_ptr _renderer;
  unique_vector _children;
};
} // namespace grumble
