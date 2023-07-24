//
//  Game.hpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#pragma once

#include <chrono>
#include <string>
#include <memory>

#import "Object.hpp"
#import "../ui/View.hpp"
#import "../logging/Logger.hpp"
#import "../util/Time.hpp"
#import "../render/RendererManager.hpp"
#import "../ui/ViewFactory.hpp"

namespace grumble {
  class Game: public Object {
  public:
    Game(std::shared_ptr<RendererManager> rendererManager);
    ~Game();
    
    void setup(float renderScale);
    
    void update(double dt);
    void render();
    
    std::shared_ptr<ViewFactory> viewFactory();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    std::shared_ptr<RendererManager> _rendererManager;
    std::shared_ptr<ViewFactory> _viewFactory;
    
    std::shared_ptr<View> _rootView;
  };
}
