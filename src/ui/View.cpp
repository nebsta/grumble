//
//  View.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "View.hpp"
#include <memory>

namespace grumble {
View::View(Renderer::unique_ptr renderer, HMM_Vec2 position, HMM_Vec2 size,
           TransformOrigin origin)
    : _transform(std::make_shared<Transform>(position, size, origin)),
      _renderer(std::move(renderer)) {}

View::View(uint32_t instanceId, HMM_Vec2 position, HMM_Vec2 size,
           TransformOrigin origin)
    : View(std::make_unique<Renderer>(instanceId), position, size, origin) {}

View::~View() { _children.clear(); }

void View::update(const float &dt) {
  if (spriteAnimator != nullptr) {
    spriteAnimator->update(dt);

    SpriteDefinition sprite = spriteAnimator->currentFrame();
    _renderer->setSprite(sprite);
    _transform->setSize(sprite.size);
  }

  if (hasChildren()) {
    unique_iterator iter = _children.begin();
    for (; iter != _children.end(); iter++) {
      (*iter)->update(dt);
    }
  }
}

void View::updateInstanceBuffer(RendererManager::shared_ptr rendererManager,
                                double t) {

  HMM_Mat4 modelMatrix = _transform->modelMatrix(1.0f);
  uint32_t instanceId = _renderer->instanceId();

  SpriteDefinition sprite = _renderer->sprite();
  HMM_Vec2 spriteSize = sprite.size;
  HMM_Vec2 uvOrigin = sprite.region.bl;
  HMM_Vec2 uvSize = sprite.region.size();
  float uvScaleFactorX = _transform->size().Width / spriteSize.Width;
  float uvScaleFactorY = _transform->size().Height / spriteSize.Height;
  ViewInstance instance =
      (ViewInstance){.uv0 = {sprite.region.tl.X * uvScaleFactorX,
                             sprite.region.tl.Y * uvScaleFactorY},
                     .uv1 = {sprite.region.tr.X * uvScaleFactorX,
                             sprite.region.tr.Y * uvScaleFactorY},
                     .uv2 = {sprite.region.br.X * uvScaleFactorX,
                             sprite.region.br.Y * uvScaleFactorY},
                     .uv3 = {sprite.region.bl.X * uvScaleFactorX,
                             sprite.region.bl.Y * uvScaleFactorY},
                     .uvs = uvSize,
                     .uvo = uvOrigin,
                     .colx = modelMatrix.Columns[0],
                     .coly = modelMatrix.Columns[1],
                     .colz = modelMatrix.Columns[2],
                     .colw = modelMatrix.Columns[3]};

  rendererManager->updateInstanceBuffer(instanceId, instance, t);

  if (!hasChildren()) {
    return;
  }

  // updating the buffers for the child views
  auto iter = _children.begin();
  for (; iter != _children.end(); iter++) {
    (*iter)->updateInstanceBuffer(rendererManager, t);
  }
}

#pragma mark Child Management

void View::addChild(View::unique_ptr child) {

  // check if the child view already exists in the hierarchy
  if (hasChildren()) {
    unique_iterator pos = std::find(_children.begin(), _children.end(), child);
    if (pos != _children.end()) {
      logWarn(
          "Trying to add a child view when it already belongs to the parent");
      return;
    }
  }
  child->setParent(_transform);

  _children.push_back(std::move(child));
}

void View::setParent(std::weak_ptr<Transform> parent) {
  _transform->setParent(parent);
}

bool View::hasChildren() const { return _children.size() != 0; }

#pragma mark Setters

void View::setPosition(HMM_Vec2 pos) { _transform->setLocalPosition(pos); }
void View::setSize(HMM_Vec2 size) { _transform->setSize(size); }
void View::setSprite(SpriteDefinition sprite) { _renderer->setSprite(sprite); }

} // namespace grumble
