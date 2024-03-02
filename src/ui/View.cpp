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
             Renderer::shared_ptr renderer,
             ViewType type) :
    _transform(std::make_shared<Transform>(position, size, origin)),
    _renderer(renderer),
    _type(type) {
    
  }

  View::~View() {
    _children.clear();
  }

  void View::update(const float& dt) {
    if (hasChildren()) {
      for (iterator iter = _children.begin(); iter != _children.end(); iter++) {
        (*iter)->update(dt);
      }
    }
  }

  #pragma mark Child Management

  void View::addChild(View::shared_ptr child) {
    iterator pos = std::find(_children.begin(), _children.end(), child);
    if (pos != _children.end()) {
      return;
    }
    _children.push_back(child);
    
    child->transform()->setParent(_transform);
  }

  bool View::hasChildren() const {
    return _children.size() != 0;
  }

  #pragma mark Getters

  Transform::shared_ptr View::transform() {
    return _transform;
  }

  Renderer::shared_ptr View::renderer() {
    return _renderer;
  }

  View::iterator View::childIteratorBegin() {
    return _children.begin();
  }

  View::iterator View::childIteratorEnd() {
    return _children.end();
  }

  const ViewType View::type() const {
    return _type;
  }
}
