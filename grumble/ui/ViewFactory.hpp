//
//  ViewFactory.hpp
//  grumble
//
//  Created by Benjamin Wallis on 22/07/2023.
//

#pragma once

#import <memory>
#include <glm/glm.hpp>

#import "../ui/View.hpp"

namespace grumble {
  class ViewFactory: public grumble::Object {
  public:
    ViewFactory(std::shared_ptr<RendererManager> rendererManager);
    ~ViewFactory();
    
    std::shared_ptr<View> createView();
    
  private:
    std::shared_ptr<RendererManager> _rendererManager;
  };
}
