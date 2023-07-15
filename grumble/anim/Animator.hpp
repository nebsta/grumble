//
//  Animator.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "../base/Object.hpp"
#include "AnimationCurves.hpp"

#define ANIMATOR_DEFAULT_DURATION 4.0f

namespace grumble {
  class Animator : public Object {
  public:
    Animator();
    ~Animator();
    
    void update(float dt);
    
    virtual void updateProperty() = 0;
    virtual void reset() = 0;
    
    void play();
    void resume();
    void stop();
    void pause();
    
    bool isPlaying() const;
    bool hasStarted() const;
    
    virtual Animator* setDuration(float duration);
    virtual Animator* setLoop(bool loop);
    virtual Animator* setAnimationCurve(BezierCurve curve);
    
  private:
    float _timer;
    float _duration;
    bool _playing;
    bool _loop;
    BezierCurve _curve;
    
    void calculateValue();
    
  protected:
    float _value;
  };
}
