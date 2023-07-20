//
//  ShaderManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>
#include <map>

#include "../logging/Logger.hpp"
#include "ShaderHandler.hpp"

namespace grumble {
  class ShaderManager {
    
  public:
    static ShaderManager& instance() {
      static ShaderManager instance;
      return instance;
    }
    
    template<typename T>
    void initialize(ShaderHandler *handler);
    void teardown();
    
  private:
    std::unique_ptr<ShaderHandler> _shaderHandler;
    
    ShaderManager();
    ~ShaderManager();
  };
}
