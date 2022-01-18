//
//  Object.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <sstream>

#include "Logger.hpp"

#define CORE_DEFAULT_ID 0

namespace grumble {
    class Object {
        
    public:
        Object();
        Object(int id);
        ~Object();
        
        int id();
        void setId(int id);
        
        void print();
        
        std::string toString();
        std::stringstream toStream();
        
    private:
        int _id;
    };
}

#endif /* Object_hpp */
