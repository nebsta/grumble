//
//  ScreenManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#pragma once

#include <stdio.h>
#include <memory>

#include "ScreenHandler.hpp"

namespace grumble {
  class ScreenManager {
  public:
    
    ScreenManager();
    ~ScreenManager();
    
    template<typename T>
    void initialize();
    
    const ScreenHandler& screenHandler();
    
    float screenHeight() const;
    float screenWidth() const;
    
  private:
    
    std::unique_ptr<ScreenHandler> _screenHandler;
  };
}
