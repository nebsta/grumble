//
//  View.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "View.hpp"

namespace grumble {
    typedef std::vector<View*>::iterator ViewIterator;

    View::View() : View(VIEW_DEFAULT_POSITION) {
        
    }

    View::View(const glm::vec2& position) : View(position,VIEW_DEFAULT_SIZE) {
        
    }

    View::View(const glm::vec2& position, const glm::vec2& size) : View(position,size,VIEW_DEFAULT_COLOR) {
        
    }

    View::View(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) : View(position,size, Graphics::CreateViewRenderer(color))
    {

    }

    View::View(const glm::vec2& position, const glm::vec2& size, Renderer* renderer) :
    _renderer(renderer),
    _transform(position,size),
    _responder(_transform),
    _screenManager(ScreenManager::instance()) {
        refreshRendererMatrix();
        refreshRendererClip();
    }

    View::~View() {
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            delete *iter;
        }
        _children.clear();
    }

    void View::render() {
        _renderer->render();
        
        if (!hasChildren()) {
            return;
        }
        
        _renderer->pushClippingRect();
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            (*iter)->render();
        }
        _renderer->popClippingRect();
    }

    void View::update(const float& dt) {
        
        if (_animator.isPlaying()) {
            
            if (!_animator.hasStarted()) {
              _animator.setup(_transform.localPosition(), _transform.size());
            }
            
            _animator.update(dt);
            _transform.setLocalPosition(_animator.resultPosition());
            _transform.setSize(_animator.resultSize());
        }
        
        if (_transform.consumePropertyChanges()) {
            refreshRendererMatrix();
            refreshRendererClip();
        
            if (!_animator.isPlaying()) {
                _animator.setStartPosition(_transform.localPosition());
                _animator.setEndPosition(_transform.localPosition());
                _animator.setStartSize(_transform.size());
                _animator.setEndSize(_transform.size());
                
            }
        }
      
        if (hasChildren()) {
            for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
                (*iter)->update(dt);
            }
        }
    }

    void View::consumeTransformChanges() {

    }

    #pragma mark Renderer Refreshing

    void View::refreshRendererMatrix() {
        glm::mat4 matrix = _transform.matrix();
        _renderer->setModelviewMatrix(matrix);
        
        if (!hasChildren()) {
            return;
        }
        
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            (*iter)->refreshRendererMatrix();
        }
    }

    void View::refreshRendererClip() {
        glm::vec4 rect = _transform.rect();
        _renderer->setClippingRect(rect);
        
        if (!hasChildren()) {
            return;
        }
        
        for (ViewIterator iter = _children.begin(); iter != _children.end(); iter++) {
            (*iter)->refreshRendererClip();
        }
    }

    #pragma mark Input

    void View::touchBegin(Touch touch) {
        _responder.onTouchBegin(touch);
    }

    void View::touchEnd(Touch touch) {
        _responder.onTouchEnd(touch);
    }

    void View::setOnTouchBegin(std::function<void (Touch)> callback) {
        _responder.setOnTouchBeginCallback(callback);
    }

    void View::setOnTouchEnd(std::function<void (Touch)> callback) {
        _responder.setOnTouchEndCallback(callback);
    }

    #pragma mark Child Management

    void View::addChild(View* const child) {
        
        if (child == nullptr) {
            return;
        }
        
        ViewIterator pos = std::find(_children.begin(), _children.end(), child);
        if (pos != _children.end()) {
            return;
        }
        _children.push_back(child);
      
        child->transform().setParent(&_transform);
        
        _responder.addChild(&child->responder());
        
        refreshRendererMatrix();
        refreshRendererClip();
    }

    void View::removeChild(View* const child) {
        
        if (child == nullptr) {
            return;
        }
        
        ViewIterator pos = std::find(_children.begin(), _children.end(), child);
        if (pos == _children.end()) {
            return;
        }
        _children.erase(pos);
      
        child->transform().setParent(nullptr);
        
        refreshRendererMatrix();
        refreshRendererClip();
    }

    bool View::hasChildren() const {
        return _children.size() != 0;
    }

    #pragma mark Getters

    Renderer* const View::renderer() {
        return _renderer.get();
    }

    Transform& View::transform() {
        return _transform;
    }

    Responder& View::responder() {
        return _responder;
    }

    ViewAnimator& View::animator() {
        return _animator;
    }
}
