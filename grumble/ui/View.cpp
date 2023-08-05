//
//  View.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "View.hpp"

namespace grumble {
  View::View(glm::vec2 position,
             glm::vec2 size,
             TransformOrigin origin,
             std::shared_ptr<Renderer> renderer) :
    _transform(position, size, origin),
    _renderer(renderer) {
    
    
  }

  View::~View() {
    _children.clear();
  }

  void View::update(const float& dt) {
    if (hasChildren()) {
      for (Iterator iter = _children.begin(); iter != _children.end(); iter++) {
        (*iter)->update(dt);
      }
    }
  }

  #pragma mark Child Management

  void View::addChild(std::shared_ptr<View> child) {
    Iterator pos = std::find(_children.begin(), _children.end(), child);
    if (pos != _children.end()) {
      return;
    }
    _children.push_back(child);
    
    child->transform().setParent(&_transform);
  }

  bool View::hasChildren() const {
    return _children.size() != 0;
  }

  #pragma mark Getters

  Transform& View::transform() {
    return _transform;
  }

  std::shared_ptr<Renderer> View::renderer() {
    return _renderer;
  }

  View::Iterator View::childIteratorBegin() {
    return _children.begin();
  }

  View::Iterator View::childIteratorEnd() {
    return _children.end();
  }
}
