//
//  IUpdatable.h
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef IUpdatable_h
#define IUpdatable_h

class IUpdatable {
public:
    virtual void update(float dt) = 0;
    
    void setEnabled(bool enabled) {
        this->enabled = enabled;
    }
    
    bool isEnabled() {
        return enabled;
    }
    
private:
    bool enabled = true;
};

#endif /* IUpdatable_h */
