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
#include <fmt/core.h>

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
    
    virtual const std::string toString() const;
    
  protected:
    virtual LogCategory logCategory() { return LogCategory::none; }
    
    template <typename... T>
    void logDebug(std::string message, T&&... args) {
      Logger::debug(message, logCategory(), args...);
    }
    
    void logInfo(std::string message);
    void logWarn(std::string message);
    void logError(std::string message);
    
    int _id;
  };
}

