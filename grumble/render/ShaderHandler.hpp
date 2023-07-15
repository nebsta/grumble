//
//  ShaderHandler.hpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#pragma once

#include <stdio.h>

namespace grumble {
  class ShaderHandler {
  public:
    virtual void initialize() = 0;
    virtual ~ShaderHandler() = 0;
  private:
  };
}

