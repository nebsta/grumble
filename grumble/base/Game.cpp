//
//  Game.cpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#include "Game.hpp"

#define FIXED_UPDATE_MS DurationMilliseconds(100)
#define FPS DurationSeconds(30.0f)
#define TIME_PER_FRAME_MS DurationMilliseconds(1.0f / FPS.count())

namespace grumble {
  Game::Game(ScreenManager *screenManager) {
    _screenManager = screenManager;
    
  }

  Game::~Game() {
    delete _screenManager;
    _screenManager = nullptr;
  }

#pragma mark Public Methods

  void Game::setup() {
    _screenManager->setup();
  }

  void Game::executeLoop(double dt) {
    logDebug("Execute Loop. Delta: " + std::to_string(dt));

    update(dt);
    render();
  }

#pragma mark Private Methods

  void Game::update(double dt) {
//    _rootView->update(dt);
  }

  void Game::fixedUpdate() {
    
  }

  void Game::render() {
//    _rootView->render();
  }

#pragma mark Protected Methods
  LogCategory Game::logCategory() {
    return LogCategory::core;
  }
}
