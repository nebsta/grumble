//
//  Game.hpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#pragma once

#import "Object.hpp"
#import "../ui/ScreenManager.hpp"
#import "../ui/View.hpp"

namespace grumble {
  class Game: public Object {
    Game(ScreenManager *screenManager, View *rootView);
    ~Game();
    
    void setup();
    void render();
    void update(float dt);
    
  private:
    ScreenManager *_screenManager;
    View *_rootView;
  };
}
