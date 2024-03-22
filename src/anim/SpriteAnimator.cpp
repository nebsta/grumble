#include "SpriteAnimator.hpp"
#include "AnimationDirection.hpp"
#include "ReplayBehaviour.hpp"

namespace grumble {

SpriteAnimator::SpriteAnimator(SpriteAnimatorConfiguration config,
                               SpriteDefinition::vector frames)
    : _config(config), _frames(frames), _currentFrameIndex(0),
      _animFrameTime((0.0)), _currentDirection(AnimationDirection::Forwards),
      _isPlaying(false) {
  if (_config.playImmediately) {
    start();
  }
}

SpriteAnimator::~SpriteAnimator() {}

void SpriteAnimator::update(double dt) {
  if (!_isPlaying) {
    return;
  }

  _animFrameTime += dt;

  if (_animFrameTime < _config.frameDelay) {
    return;
  }

  _animFrameTime -= _config.frameDelay;

  _currentFrameIndex += _currentDirection;
  if (!isAnimationFinished()) {
    return;
  }

  switch (_config.replayBehaviour) {
  case ReplayBehaviour::PlayOnce:
    return;
  case ReplayBehaviour::PingPong:
    switch (_currentDirection) {
    case AnimationDirection::Backwards:
      _currentDirection = AnimationDirection::Forwards;
      _currentFrameIndex = 0;
    case AnimationDirection::Forwards:
      _currentDirection = AnimationDirection::Backwards;
      _currentFrameIndex = _frames.size() - 1;
    }
  case ReplayBehaviour::RepeatFromBeginning:
    _currentFrameIndex = 0;
  }
}

void SpriteAnimator::start() {
  if (_isPlaying) {
    logWarn("Trying to start sprite animator when it's already playing");
    return;
  }

  reset();
  _isPlaying = true;
}

void SpriteAnimator::stop() {
  if (!_isPlaying) {
    logWarn("Trying to stop sprite animator when it's not playing");
    return;
  }

  reset();
  _isPlaying = false;
}

bool SpriteAnimator::isPlaying() const { return _isPlaying; }

SpriteDefinition SpriteAnimator::currentFrame() const {
  return _frames[_currentFrameIndex];
}

void SpriteAnimator::reset() {
  _currentDirection = AnimationDirection::Forwards;
  _currentFrameIndex = 0;
  _animFrameTime = 0.0;
}

bool SpriteAnimator::isAnimationFinished() const {
  return _currentFrameIndex <= 0 || _currentFrameIndex >= _frames.size();
}

}; // namespace grumble
