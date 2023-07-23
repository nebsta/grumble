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
    _viewFactory = std::make_shared<grumble::ViewFactory>(grumble::ViewFactory(_rendererManager));
  }

  Game::~Game() {
    
  }

#pragma mark Public Methods

  void Game::setup() {
    _screenManager->setup();
  }

  View* Game::rootView() const {
    return _rootView;
  }

  std::shared_ptr<ViewFactory> Game::viewFactory() {
    return _viewFactory;
  }

#pragma mark Private Methods
  void Game::update(double dt) {
    logDebug("Update. Delta: " + std::to_string(dt));
    _rootView->update(dt);
  }

  void Game::fixedUpdate() {
    
  }

  void Game::render() {
    _rootView->render();
  }

#pragma mark Protected Methods

  LogCategory Game::logCategory() {
    return LogCategory::core;
  }
}
