//
//  Game.cpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#include "Game.hpp"
#include <memory>

namespace grumble {
Game::Game(RendererManager::shared_ptr rendererManager,
           FileManager::shared_ptr fileManager,
           SpriteManager::shared_ptr spriteManager,
           FontManager::shared_ptr fontManager,
           InputManager::shared_ptr inputManager)
    : _rendererManager(rendererManager), _fileManager(fileManager),
      _spriteManager(spriteManager),
      _viewFactory(std::make_shared<ViewFactory>(fontManager)),
      _fontManager(fontManager), _inputManager(inputManager),
      _rootView(_viewFactory->createView({0.0f, 0.0f})),
      _camera(std::make_shared<Camera>()),
      _debugState(std::make_shared<DebugState>()) {
  _rootView->renderer()->setTint(COLOR_WHITE);
  _rendererManager->setDebugState(_debugState);
}

Game::~Game() {}

#pragma mark Public Methods

void Game::setup() {
  _spriteManager->setup();
  _fontManager->setup();
  _rendererManager->setup();
}

void Game::teardown() { _rendererManager->teardown(); }

bool Game::input() { return _inputManager->update(); }

void Game::update(double dt) { _rootView->update(dt); }

void Game::render() {
  _rendererManager->prepareFrame();
  _rendererManager->renderFrame(_rootView);
  _rendererManager->commitFrame();
}

void Game::reset() { _inputManager->clearTriggeredInputs(); }

void Game::setScreenSize(HMM_Vec2 size) {
  _rendererManager->setScreenSize(size);
  _rootView->transform()->setSize({size.Width, size.Height});
}

void Game::setCameraPosition(HMM_Vec2 pos) {
  _camera->setPosition(pos);
  _rendererManager->setCameraPosition(pos);
}

void Game::moveCameraPosition(HMM_Vec2 by) {
  auto newPos = _camera->position() + by;
  _camera->setPosition(newPos);
  _rendererManager->setCameraPosition(newPos);
}

View::shared_ptr Game::rootView() { return _rootView; }

ViewFactory::shared_ptr Game::viewFactory() { return _viewFactory; }

FileManager::shared_ptr Game::fileManager() { return _fileManager; }

FontManager::shared_ptr Game::fontManager() { return _fontManager; }

SpriteManager::shared_ptr Game::spriteManager() { return _spriteManager; }

InputManager::shared_ptr Game::inputManager() { return _inputManager; }

Camera::shared_ptr Game::camera() { return _camera; }

DebugState::shared_ptr Game::debugState() { return _debugState; }

#pragma mark Protected Methods

LogCategory Game::logCategory() const { return LogCategory::core; }
} // namespace grumble
