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
#import "../ui/ScreenManager.hpp"
#import "../ui/View.hpp"
#import "../logging/Logger.hpp"
#import "../util/Time.hpp"
#import "../render/RendererManager.hpp"

namespace grumble {
  class Game: public Object {
  public:
    Game(std::shared_ptr<ScreenManager> screenManager, std::shared_ptr<RendererManager> rendererManager);
    ~Game();
    
    void setup();
    
    void update(double dt);
    void render();
    
    View* rootView() const;
    
  protected:
    LogCategory logCategory() override;
    
  private:
    std::shared_ptr<ScreenManager> _screenManager;
    std::shared_ptr<RendererManager> _rendererManager;
    
    std::shared_ptr<View> _rootView;
  };
}
