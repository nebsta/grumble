#include "ImageView.hpp"
#include <fmt/core.h>

namespace grumble {
ImageView::ImageView(const std::string &id, const SpriteDefinition &sprite,
                     HMM_Vec2 position, HMM_Vec2 size, TransformOrigin origin)
    : View(id), _transform(std::make_unique<Transform>(
                    fmt::format("{}_transform", id), position, size, origin)),
      _responder({nullptr, nullptr}), _sprite(sprite) {}

ImageView::~ImageView() {}

void ImageView::update(double dt, FrameInput &input) {
  if (_spriteAnimator != nullptr) {
    _spriteAnimator->update(dt);

    _sprite = _spriteAnimator->currentFrame();
    _transform->setSize(_sprite.size);
  }

  if (_isInteractive && !input.handled) {
    bool containsPoint = _transform->containsPoint(input.touchPosition);
    if (containsPoint) {
      input.handled = true;
      if (_responder.onTouchDown != nullptr) {
        _responder.onTouchDown();
      }
    }
  }
}

void ImageView::pushBuffer(InstanceBufferCollection &collection, double t) {
  if (_sprite.isEmpty()) {
    return;
  }

  HMM_Mat4 modelMatrix = _transform->modelMatrix(1.0f);
  HMM_Vec2 spriteSize = _sprite.size;
  HMM_Vec2 uvOrigin = _sprite.region.bl;
  HMM_Vec2 uvSize = _sprite.region.size();
  float uvScaleFactorX = _transform->size().Width / spriteSize.Width;
  float uvScaleFactorY = _transform->size().Height / spriteSize.Height;
  ViewInstance instance =
      (ViewInstance){.uv0 = {_sprite.region.tl.X * uvScaleFactorX,
                             _sprite.region.tl.Y * uvScaleFactorY},
                     .uv1 = {_sprite.region.tr.X * uvScaleFactorX,
                             _sprite.region.tr.Y * uvScaleFactorY},
                     .uv2 = {_sprite.region.br.X * uvScaleFactorX,
                             _sprite.region.br.Y * uvScaleFactorY},
                     .uv3 = {_sprite.region.bl.X * uvScaleFactorX,
                             _sprite.region.bl.Y * uvScaleFactorY},
                     .uvs = uvSize,
                     .uvo = uvOrigin,
                     .colx = modelMatrix.Columns[0],
                     .coly = modelMatrix.Columns[1],
                     .colz = modelMatrix.Columns[2],
                     .colw = modelMatrix.Columns[3]};
  collection.push(instance);
}

#pragma mark Getters

HMM_Vec2 ImageView::position() const { return _transform->position(); }

HMM_Vec2 ImageView::size() const { return _transform->size(); }

#pragma mark Setters

void ImageView::setPosition(HMM_Vec2 pos) { _transform->setPosition(pos); }

void ImageView::setSize(HMM_Vec2 size) { _transform->setSize(size); }

void ImageView::setSprite(const SpriteDefinition &sprite) { _sprite = sprite; }

} // namespace grumble
