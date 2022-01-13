//
//  ViewAnimator.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "ViewAnimator.hpp"

ViewAnimator::ViewAnimator(glm::vec2 startPosition, glm::vec2 startSize) :
_startPosition(startPosition),
_startSize(startSize),
_endPosition(VECTOR_NEGATIVE),
_endSize(VECTOR_NEGATIVE),
_resultPosition(VECTOR_EMPTY),
_resultSize(VECTOR_EMPTY),
_currentPosition(VECTOR_EMPTY),
_currentSize(VECTOR_EMPTY) {
    
}

ViewAnimator::ViewAnimator() : ViewAnimator(VIEW_ANIM_DEFAULT_START_POS,VIEW_ANIM_DEFAULT_START_SIZE) {
    
}

ViewAnimator::~ViewAnimator() {
    
}

void ViewAnimator::updateProperty() {
    _resultPosition = glm::lerp(_startPosition, _endPosition, _value);
    _resultSize = glm::lerp(_startSize, _endSize, _value);
}

void ViewAnimator::setup(glm::vec2 currentPosition, glm::vec2 currentSize) {
  if (_startPosition == VECTOR_NEGATIVE) {
    _startPosition = currentPosition;
  }
  
  if (_endPosition == VECTOR_NEGATIVE) {
    _endPosition = currentPosition;
  }
  
  if (_startSize == VECTOR_NEGATIVE) {
    _startSize = currentSize;
  }
  
  if (_endSize == VECTOR_NEGATIVE) {
    _endSize = currentSize;
  }
}

void ViewAnimator::reset() {
    _startPosition = VECTOR_NEGATIVE;
    _endPosition = VECTOR_NEGATIVE;
    _startSize = VECTOR_NEGATIVE;
    _endSize = VECTOR_NEGATIVE;
}

ViewAnimator* ViewAnimator::setLoop(bool loop) {
    return (ViewAnimator*)Animator::setLoop(loop);
}

ViewAnimator* ViewAnimator::setDuration(float duration) {
    return (ViewAnimator*)Animator::setDuration(duration);
}

ViewAnimator* ViewAnimator::setAnimationCurve(BezierCurve curve) {
    return (ViewAnimator*)Animator::setAnimationCurve(curve);
}

ViewAnimator* ViewAnimator::setStartPosition(glm::vec2 position) {
    _startPosition = position;
    return this;
}

ViewAnimator* ViewAnimator::setStartSize(glm::vec2 size) {
    _startSize = size;
    return this;
}

ViewAnimator* ViewAnimator::setEndPosition(glm::vec2 position) {
    _endPosition = position;
    return this;
}

ViewAnimator* ViewAnimator::setEndSize(glm::vec2 size) {
    _endSize = size;
    return this;
}

ViewAnimator* ViewAnimator::animateByPosition(glm::vec2 position) {
    _endPosition = _currentPosition + position;
    return this;
}

ViewAnimator* ViewAnimator::animateBySize(glm::vec2 size) {
    _endSize = _currentSize + size;
    return this;
}

glm::vec2 ViewAnimator::resultPosition() const {
    return _resultPosition;
}

glm::vec2 ViewAnimator::resultSize() const {
    return _resultSize;
}

glm::vec2 ViewAnimator::startSize() const {
    return _startSize;
}

glm::vec2 ViewAnimator::endSize() const {
    return _endSize;
}

glm::vec2 ViewAnimator::startPosition() const {
    return _startPosition;
}

glm::vec2 ViewAnimator::endPosition() const {
    return _endPosition;
}
