//
//  Transform.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 7/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Transform.hpp"

namespace grumble {
    Transform::Transform() : Transform(TRANSFORM_DEFAULT_POSITION) {
        
    }

    Transform::Transform(glm::vec2 position) : Transform(position,TRANSFORM_DEFAULT_SIZE) {
        
    }

    Transform::Transform(glm::vec2 position, glm::vec2 size) :
    _localPosition(position),
    _size(size),
    _constraint(TransformConstraint_None),
    _parent(nullptr),
    _screenHandler(ScreenManager::instance().screenHandler()) {
        
    }

    Transform::~Transform() {
        _parent = nullptr;
    }

    #pragma mark Setters

    void Transform::setLocalPosition(glm::vec2 localPosition) {
        _localPosition = localPosition;
        _propertiesChanged = true;
    }

    void Transform::setSize(glm::vec2 size) {
        _size = size;
        _propertiesChanged = true;
    }

    void Transform::setConstraint(TransformConstraint constraint) {
        _constraint = constraint;
        _propertiesChanged = true;
    }

    void Transform::setParent(Transform* const parent) {
        _parent = parent;
        _propertiesChanged = true;
    }

    #pragma mark Getters

    glm::vec2 Transform::localPosition() const {
        return _localPosition;
    }

    glm::vec2 Transform::screenPosition() const {
        glm::vec2 result = glm::vec2();
        if (_parent != nullptr) {
            result = _parent->screenPosition();
        }
        return result + _localPosition;
    }

    const bool Transform::hasParent() const {
      return _parent != nullptr;
    }

    const glm::mat4 Transform::matrix() const {
        glm::mat4 matrix = glm::mat4();
        glm::vec2 resultPosition = screenPosition();
        glm::vec2 resultSize = size();
        
        matrix = glm::translate(matrix, glm::vec3(resultPosition.x,resultPosition.y,0.0f));
        
        // Applying view constraints
        if (_constraint != TransformConstraint_None && hasParent()) {
            glm::vec2 parentSize = _parent->size();
            if (_constraint == TransformConstraint_FillX) {
                resultSize.x = parentSize.x;
            } else if (_constraint == TransformConstraint_FillY) {
                resultSize.y = parentSize.y;
            } else {
                resultSize = parentSize;
            }
        }
        
        matrix = glm::scale(matrix, glm::vec3(resultSize.x,resultSize.y,1.0f));
        return matrix;
    }

    const glm::vec2 Transform::size() const {
        return _size;
    }

    const bool Transform::consumePropertyChanges() {
        if (!_propertiesChanged) {
            return false;
        }
        _propertiesChanged = false;
        return true;
    }

    const glm::vec4 Transform::rect() const {
        glm::vec2 pixelPosition = _screenHandler.convertToPixels(screenPosition());
        glm::vec2 pixelSize = _screenHandler.convertToPixels(size());
        
        glm::vec4 rect;
        rect.x = pixelPosition.x;
        rect.y = _screenHandler.screenPixelSize().y - (pixelPosition.y + pixelSize.y);
        rect.z = pixelSize.x;
        rect.w = pixelSize.y;
        
        return rect;
    }

    bool Transform::containsLocalPoint(glm::vec2 point) const {
        return point.x >= _localPosition.x && point.y >= _localPosition.y &&
               point.x <= _localPosition.x + _size.x && point.y <= _localPosition.y + _size.y;
    }

    bool Transform::containsScreenPoint(glm::vec2 point) const {
        glm::vec2 sPos = screenPosition();
        
        return point.x >= sPos.x && point.y >= sPos.y &&
               point.x <= sPos.x + _size.x && point.y <= sPos.y + _size.y;
    }
}
