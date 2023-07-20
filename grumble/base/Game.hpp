//
//  Game.hpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#pragma once

#include <chrono>
#include <string>

#import "Object.hpp"
#import "../ui/ScreenManager.hpp"
#import "../ui/View.hpp"
#import "../logging/Logger.hpp"
#import "../util/Time.hpp"

namespace grumble {
  class Game: public Object {
  public:
    Game(ScreenManager *screenManager);
    ~Game();
    
    void setup();
    void executeLoop(double dt);
    
  protected:
    LogCategory logCategory() override;
    
  private:
    ScreenManager *_screenManager;
    View *_rootView;
    
    void render();
    void update(double dt);
    void fixedUpdate();
  };
}
