//
//  Animator.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Animator.hpp"

namespace grumble {
    Animator::Animator() :
    _duration(ANIMATOR_DEFAULT_DURATION),
    _timer(0),
    _value(0),
    _loop(false),
    _curve(CURVE_LINEAR),
    _playing(false) {
        
    }

    Animator::~Animator() {

    }

    void Animator::update(float dt) {
        if (_playing) {
            _timer += dt;
            
            calculateValue();
            updateProperty();
            
            if (_timer >= _duration) {
                
                if (_loop) {
                    _timer = 0.0f;
                    _value = 0.0f;
                    return;
                }
                
                reset();
                stop();
            }
        }
    }

    void Animator::play() {
        _playing = true;
        _timer = 0.0f;
        _value = 0.0f;
    }

    void Animator::stop() {
        _playing = false;
        _timer = 0.0f;
        _value = 0.0f;
    }

    void Animator::pause() {
        _playing = false;
    }

    void Animator::resume() {
        _playing = true;
    }

    bool Animator::isPlaying() const {
        return _playing;
    }

    bool Animator::hasStarted() const {
        return _timer > 0;
    }

    Animator* Animator::setDuration(float duration) {
        _duration = duration;
        return this;
    }

    Animator* Animator::setAnimationCurve(BezierCurve curve) {
        _curve = curve;
        return this;
    }

    Animator* Animator::setLoop(bool loop) {
        _loop = loop;
        return this;
    }

    void Animator::calculateValue() {
        float relativeTime = _timer / _duration;
        _value = cubicBezier(_curve.x1, _curve.y1, _curve.x2, _curve.y2, relativeTime).y;
        if (relativeTime >= 1) {
            _value = 1.0f;
        }
    }
}
