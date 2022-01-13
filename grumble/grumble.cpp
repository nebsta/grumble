//
//  grumble.cpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#include <iostream>
#include "grumble.hpp"
#include "grumblePriv.hpp"

void grumble::HelloWorld(const char * s)
{
    grumblePriv *theObj = new grumblePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void grumblePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

