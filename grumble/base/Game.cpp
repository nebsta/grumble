//
//  Game.cpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#include "Game.hpp"

#define FIXED_UPDATE_MS DurationMilliseconds(100)
#define FPS DurationSeconds(60.0f)
#define TIME_PER_FRAME_MS DurationMilliseconds(1.0f / FPS.count())

namespace grumble {
  Game::Game(/*ScreenManager *screenManager, View *rootView*/)/* : _screenManager(screenManager), _rootView(rootView)*/ {
    _shouldClose = false;
    _isRunning = false;
  }

  Game::~Game() {
    delete _screenManager;
    _screenManager = nullptr;
    
    _shouldClose = true;
  }

  void Game::setup() {
    _screenManager->setup();
  }

  void Game::start() {
    if (_isRunning) {
      return;
    }
    
    _uiThreadId = std::this_thread::get_id();
    _isRunning = true;
    
    _mainThread = std::thread(&Game::mainLoop, this);
    _mainThread.detach();
  }

  void Game::mainLoop() {
    auto frameStartPrev = std::chrono::system_clock::now();
    DurationMilliseconds lag;
    while (!_shouldClose)
    {
      auto frameStart = std::chrono::system_clock::now();
      auto elapsed =  std::chrono::duration_cast<std::chrono::milliseconds>(frameStart - frameStartPrev);
      
      logDebug("Frame Start");
      logDebug("Elapsed Time " + std::to_string(elapsed.count()));

      frameStartPrev = frameStart;
      lag += elapsed;

      logDebug("Fixed Update Lag " + std::to_string(lag.count()));
      while (lag >= FIXED_UPDATE_MS) {
        fixedUpdate();
        lag -= FIXED_UPDATE_MS;
      }

      update(elapsed.count());
      render();

      logDebug("Frame End");

      auto frameEnd = std::chrono::system_clock::now();
      DurationMilliseconds frameDuration = frameEnd - frameStart;
      logDebug("Frame Duration: " + std::to_string(frameDuration.count()));
      if (frameDuration < TIME_PER_FRAME_MS) {
        DurationMilliseconds frameWait = TIME_PER_FRAME_MS - frameDuration;
        std::this_thread::sleep_for(frameWait);
      }
    }
    
    logDebug("LOOP EXIT");
  }

  void Game::update(double dt) {
//    _rootView->update(dt);
  }

  void Game::fixedUpdate() {
    
  }

  void Game::render() {
//    _rootView->render();
  }

  void Game::close() {
    _shouldClose = true;
  }

#pragma mark Protected Methods
  LogCategory Game::logCategory() {
    return LogCategory::core;
  }
}
