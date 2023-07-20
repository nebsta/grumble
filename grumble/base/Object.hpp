//
//  Object.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 1/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <sstream>

#include "../logging/Logger.hpp"

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
    
  protected:
    virtual LogCategory logCategory() { return LogCategory::none; }
    
    void logDebug(std::string message);
    void logInfo(std::string message);
    void logWarn(std::string message);
    void logError(std::string message);
    
  private:
    int _id;
  };
}

