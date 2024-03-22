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

#include "../render/Renderer.hpp"
#include "../render/RendererManager.hpp"

namespace grumble {
class View : public Object {
public:
  typedef std::shared_ptr<View> shared_ptr;
  typedef std::unique_ptr<View> unique_ptr;
  typedef std::weak_ptr<View> weak_ptr;

  typedef std::vector<shared_ptr> shared_vector;
  typedef std::vector<unique_ptr> unique_vector;
  typedef std::vector<weak_ptr> weak_vector;

  typedef shared_vector::iterator shared_iterator;
  typedef unique_vector::iterator unique_iterator;
  typedef weak_vector::iterator weak_iterator;

  View(uint32_t instanceId, HMM_Vec2 position = {0, 0}, HMM_Vec2 size = {0, 0},
       TransformOrigin origin = TransformOrigin::TopLeft);

  View(Renderer::unique_ptr renderer, HMM_Vec2 position = {0, 0},
       HMM_Vec2 size = {0, 0},
       TransformOrigin origin = TransformOrigin::TopLeft);

  ~View();

  void update(const float &dt);
  void updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                            double t);

  // children handling
  void setParent(std::weak_ptr<Transform> parent);
  void addChild(shared_ptr child);
  bool hasChildren() const;

  // setters
  void setPosition(HMM_Vec2 pos);
  void setSize(HMM_Vec2 size);
  void setSprite(SpriteDefinition sprite);

private:
  Transform::shared_ptr _transform;
  Renderer::unique_ptr _renderer;
  shared_vector _children;
};
} // namespace grumble
