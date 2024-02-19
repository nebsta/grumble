//
//  Message.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 24/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>

namespace grumble {
  class Message {
    
  public:
    Message();
    ~Message();
    
    void dispatch();
  };
}
