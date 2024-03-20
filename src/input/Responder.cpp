//
//  Responder.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 14/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Responder.hpp"

namespace grumble {
typedef std::vector<Responder *>::iterator ResponderIterator;

Responder::Responder(const Transform &transform)
    : _transform(transform), _onTouchBegin(nullptr), _onTouchEnd(nullptr) {}

Responder::~Responder() {
  _children.clear();

  _onTouchBegin = nullptr;
  _onTouchEnd = nullptr;
}

void Responder::setOnTouchBeginCallback(TouchCallback callback) {
  _onTouchBegin = callback;
}

void Responder::setOnTouchEndCallback(TouchCallback callback) {
  _onTouchEnd = callback;
}

void Responder::onTouchBegin(Touch touch) {

  if (!_transform.containsScreenPoint({0, 0})) {
    return;
  }

  // send callback
  if (_onTouchBegin != nullptr) {
    _onTouchBegin(touch);
  }

  if (!hasChildren()) {
    return;
  }

  // pass the touch to the child nodes
  ResponderIterator iter = _children.begin();
  for (; iter != _children.end(); iter++) {
    (*iter)->onTouchBegin(touch);
  }
}

void Responder::onTouchEnd(Touch touch) {

  //    glm::vec2 relativePos = ViewHelper::convertToSpace(touch.location,
  //    _transform->parent(), _transform); Touch relativeTouch =
  //    {touch.id,relativePos};
  //
  //    if (_transform->containsLocalPoint(touch.location)) {
  //        _responder->onTouchEnd(touch);
  //    }
  //
  //    if (_node != nullptr && _node->hasChildren()) {
  //        _node->processTouchEndChildren(relativeTouch);
  //    }
}

void Responder::addChild(Responder *const responder) {
  _children.push_back(responder);
}

bool Responder::hasChildren() const { return _children.size() != 0; }
} // namespace grumble
