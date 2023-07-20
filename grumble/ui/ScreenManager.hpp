//
//  ScreenManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#pragma once

#import <glm/glm.hpp>

namespace grumble {
  class ScreenManager {
  public:
    virtual ~ScreenManager() = default;
    
    virtual void setup() = 0;
    
    virtual glm::vec2 screenSize() const = 0;
  };
}
