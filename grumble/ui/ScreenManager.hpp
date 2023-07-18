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
    virtual ~ScreenManager() = 0;
    
    virtual void setup() = 0;
    
    virtual glm::vec2 convertToPixels(const glm::vec2& vector) const = 0;
    
    virtual float screenScale() const = 0;
    virtual float screenWidth() const = 0;
    virtual float screenHeight() const = 0;
    
    virtual glm::vec2 screenPixelSize() const = 0;
    virtual glm::vec2 screenSize() const = 0;
  };
}
