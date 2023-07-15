//
//  IUpdatable.h
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

namespace grumble {
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
}
