#pragma once

#include "../core/Object.hpp"
#include "../sprite/SpriteDefinition.hpp"
#include "AnimationDirection.hpp"
#include "SpriteAnimatorConfiguration.hpp"
#include <memory>

namespace grumble {
class SpriteAnimator : public Object {
public:
  typedef std::unique_ptr<SpriteAnimator> unique_ptr;
  typedef std::shared_ptr<SpriteAnimator> shared_ptr;

  SpriteAnimator(SpriteAnimatorConfiguration config,
                 SpriteDefinition::vector frames);
  ~SpriteAnimator();

  void update(double dt);

  void start();
  void stop();

  bool isPlaying() const;
  SpriteDefinition currentFrame() const;

private:
  AnimationDirection _currentDirection;
  int _currentFrameIndex;
  double _animFrameTime;
  bool _isPlaying;

  SpriteAnimatorConfiguration _config;
  SpriteDefinition::vector _frames;

  void reset();
  bool isAnimationFinished() const;
};
} // namespace grumble
