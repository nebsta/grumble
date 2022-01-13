//
//  ShaderHandler.hpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#ifndef ShaderHandler_hpp
#define ShaderHandler_hpp

#include <stdio.h>

class ShaderHandler {
public:
    virtual void initialize() = 0;
    virtual ~ShaderHandler() = 0;
private:
};

#endif /* ShaderHandler_hpp */
