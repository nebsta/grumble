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
  Game::Game(std::shared_ptr<RendererManager> rendererManager) {
    _rendererManager = rendererManager;
    _viewFactory = std::make_shared<ViewFactory>();
  }

  Game::~Game() {
    
  }

#pragma mark Public Methods

  void Game::setup() {
    
  }

  void Game::setRootView(std::shared_ptr<View> view) {
    _rootView = view;
  }

  void Game::update(double dt) {
    logDebug("Update. Delta: " + std::to_string(dt));
    _rootView->update(dt);
  }

  void Game::render() {
    _rendererManager->renderAll(_rootView);
  }

  std::shared_ptr<ViewFactory> Game::viewFactory() {
    return _viewFactory;
  }

#pragma mark Protected Methods

  LogCategory Game::logCategory() {
    return LogCategory::core;
  }
}
