//
//  ViewAnimator.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef ViewAnimator_hpp
#define ViewAnimator_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtx/compatibility.hpp>

#include "Animator.hpp"
#include "MathConstants.hpp"

#define VIEW_ANIM_DEFAULT_START_POS VECTOR_NEGATIVE
#define VIEW_ANIM_DEFAULT_START_SIZE VECTOR_NEGATIVE

namespace grumble {
    class ViewAnimator : public Animator {
        
    public:
        ViewAnimator();
        ViewAnimator(glm::vec2 startPosition, glm::vec2 startSize);
        ~ViewAnimator();
      
        void setup(glm::vec2 currentPosition, glm::vec2 currentSize);
        void updateProperty();
        void reset();
        
        virtual ViewAnimator* setDuration(float duration);
        virtual ViewAnimator* setLoop(bool loop);
        virtual ViewAnimator* setAnimationCurve(BezierCurve curve);
        
        glm::vec2 startPosition() const;
        glm::vec2 endPosition() const;
        glm::vec2 startSize() const;
        glm::vec2 endSize() const;
        
        glm::vec2 resultPosition() const;
        glm::vec2 resultSize() const;
        
        void setCurrentPosition(glm::vec2 position);
        void setCurrentSize(glm::vec2 size);
        
        ViewAnimator* setStartPosition(glm::vec2 position);
        ViewAnimator* setStartSize(glm::vec2 size);
        
        ViewAnimator* setEndPosition(glm::vec2 position);
        ViewAnimator* setEndSize(glm::vec2 size);
        
        ViewAnimator* animateByPosition(glm::vec2 position);
        ViewAnimator* animateBySize(glm::vec2 size);
        
    private:
        glm::vec2 _startPosition;
        glm::vec2 _endPosition;
        
        glm::vec2 _startSize;
        glm::vec2 _endSize;
        
        glm::vec2 _resultPosition;
        glm::vec2 _resultSize;
        
        glm::vec2 _currentPosition;
        glm::vec2 _currentSize;
    };
}



#endif /* ViewAnimator_hpp */
