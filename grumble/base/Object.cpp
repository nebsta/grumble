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

  void Object::print() {
    Logger::info(toString());
  }

  std::string Object::toString() {
    return toStream().str();
  }

  std::stringstream Object::toStream() {
    std::stringstream stream;
    stream << "{ id: " << _id << " }";
    return stream;
  }

  int Object::id() {
    return _id;
  }

  void Object::setId(int id) {
    this->_id = id;
  }

#pragma mark Logging
  void Object::logDebug(std::string message) {
    Logger::debug(message, this->logCategory());
  }

  void Object::logInfo(std::string message) {
    Logger::info(message, this->logCategory());
  }

  void Object::logWarn(std::string message) {
    Logger::warn(message, this->logCategory());
  }

  void Object::logError(std::string message) {
    Logger::error(message, this->logCategory());
  }
}
