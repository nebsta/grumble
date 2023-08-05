//
//  Object.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Object.hpp"

namespace grumble {
  Object::Object() : Object(CORE_DEFAULT_ID) {
    
  }

  Object::Object(int id) : _id(id) {
    
  }

  Object::~Object() {
    
  }

  const std::string Object::toString() const {
    return fmt::format("id: {}", _id);
  }

  LogCategory Object::logCategory() {
    return LogCategory::none;
  }

  int Object::id() {
    return _id;
  }

  void Object::setId(int id) {
    this->_id = id;
  }
}
