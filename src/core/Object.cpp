//
//  Object.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Object.hpp"

namespace grumble {
  Object::Object(std::string id) : _id(id) {
    
  }

  Object::~Object() {
    
  }

  const std::string Object::toString() const {
    return fmt::format("id: {}", _id);
  }

  LogCategory Object::logCategory() {
    return LogCategory::none;
  }

  std::string Object::id() const {
    return _id;
  }

  void Object::setId(std::string id) {
    _id = id;
  }
}