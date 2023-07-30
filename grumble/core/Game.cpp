//
//  Game.cpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#include "Game.hpp"

namespace grumble {
  Game::Game(std::shared_ptr<RendererManager> rendererManager,
             std::shared_ptr<FileManager> fileManager,
             std::shared_ptr<SpriteManager> spriteManager,
             std::string mainFontFile):
  _rendererManager(rendererManager),
  _fileManager(fileManager),
  _spriteManager(spriteManager),
  _viewFactory(std::make_shared<ViewFactory>()),
  _fontManager(std::make_shared<FontManager>(fileManager, mainFontFile)),
  _rootView(_viewFactory->createView({0.0f, 0.0f}, _rendererManager->screenSize())) {
    _rendererManager->setOnScreenSizeUpdated([=](glm::vec2 size) {
      this->logInfo("Resizing root view to " + glm::to_string(size));
      this->_rootView->transform().setSize(size);
    });
    _rootView->renderer().setTint(COLOR_WHITE);
  }

  Game::~Game() {
    
  }

#pragma mark Public Methods

  void Game::setup(float renderScale) {
    _spriteManager->setup();
    _rendererManager->setup(renderScale);
    _fontManager->setup();
  }

  void Game::update(double dt) {
    logDebug("Update. Delta: " + std::to_string(dt));
    _rootView->update(dt);
  }

  void Game::render() {
    _rendererManager->renderAll(_rootView);
  }

  std::shared_ptr<View> Game::rootView() {
    return _rootView;
  }

  std::shared_ptr<ViewFactory> Game::viewFactory() {
    return _viewFactory;
  }

  std::shared_ptr<FileManager> Game::fileManager() {
    return _fileManager;
  }

  std::shared_ptr<SpriteManager> Game::spriteManager() {
    return _spriteManager;
  }

#pragma mark Protected Methods

  LogCategory Game::logCategory() {
    return LogCategory::core;
  }
}
