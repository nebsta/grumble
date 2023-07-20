//
//  Game.hpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#pragma once

#include <chrono>
#include <string>
#include <thread>
#include <atomic>

#import "Object.hpp"
#import "../ui/ScreenManager.hpp"
#import "../ui/View.hpp"
#import "../logging/Logger.hpp"
#import "../util/Time.hpp"

namespace grumble {
  class Game: public Object {
  public:
    Game(/*ScreenManager *screenManager, View *rootView*/);
    ~Game();
    
    void start();
    void setup();
    
    void close();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    ScreenManager *_screenManager;
    View *_rootView;
    std::atomic<bool> _shouldClose;
    std::atomic<bool> _isRunning;
    std::thread::id _uiThreadId;
    
    std::thread _mainThread;
    
    void mainLoop();
    
    void render();
    void update(double dt);
    void fixedUpdate();
  };
}
