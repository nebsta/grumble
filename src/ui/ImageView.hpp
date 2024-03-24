//
//  View.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "Transform.hpp"

#include "../anim/SpriteAnimator.hpp"
#include "../render/Renderer.hpp"
#include "../render/RendererManager.hpp"

namespace grumble {
class ImageView : public Object {
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

  void update(const float &dt);
  void updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                            double t);

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
