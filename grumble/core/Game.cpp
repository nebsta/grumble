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
    _rendererManager->setOnScreenSizeUpdated([=](glm::vec2 size) {
      this->logInfo("Resizing root view to " + glm::to_string(size));
      this->_rootView->transform().setSize(size);
    });
    _viewFactory = std::make_shared<ViewFactory>();
    _rootView = _viewFactory->createView({0.0f, 0.0f}, _rendererManager->screenSize());
    _rootView->renderer().setTint(COLOR_GREEN);
  }

  Game::~Game() {
    
  }

#pragma mark Public Methods

  void Game::setup(float renderScale) {
    _rendererManager->setup(renderScale);
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
