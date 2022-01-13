//
//  Object.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Object.hpp"

Object::Object() : Object(CORE_DEFAULT_ID) {
    
}

Object::Object(int id) : _id(id) {
    
}

Object::~Object() {
    
}

void Object::print() {
    Logger::logMessage(toString());
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
