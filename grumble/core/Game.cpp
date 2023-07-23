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
  Game::Game(std::shared_ptr<ScreenManager> screenManager, std::shared_ptr<RendererManager> rendererManager) {
    _screenManager = screenManager;
    _rendererManager = rendererManager;
  }

  Game::~Game() {
    
  }

#pragma mark Public Methods

  void Game::setup() {
    _screenManager->setup();
  }

#pragma mark Private Methods
  void Game::update(double dt) {
    logDebug("Update. Delta: " + std::to_string(dt));
    _rootView->update(dt);
  }

  void Game::fixedUpdate() {
    
  }

  void Game::render() {
    _rendererManager->renderAll(_rootView);
  }

#pragma mark Protected Methods

  LogCategory Game::logCategory() {
    return LogCategory::core;
  }
}
