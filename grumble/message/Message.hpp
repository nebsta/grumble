//
//  Message.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 24/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef Message_hpp
#define Message_hpp

#include <stdio.h>

namespace grumble {
    class Message {
        
    public:
        Message();
        ~Message();
        
        void dispatch();
    };
}

#endif /* Message_hpp */
