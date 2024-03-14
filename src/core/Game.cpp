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
      _camera(std::make_shared<Camera>()),
      _debugState(std::make_shared<DebugState>()) {
  _rendererManager->setDebugState(_debugState);

  _viewLayers[0] = std::make_shared<ViewLayer>();
  _viewLayers[1] = std::make_shared<ViewLayer>();
  _viewLayers[2] = std::make_shared<ViewLayer>();
  _viewLayers[3] = std::make_shared<ViewLayer>();
  _viewLayers[4] = std::make_shared<ViewLayer>();
}

Game::~Game() {}

#pragma mark Public Methods

void Game::setup() {
  _spriteManager->setup();
  _fontManager->setup();
  _rendererManager->setup();
}

void Game::teardown() { _rendererManager->teardown(); }

bool Game::input() {
  bool terminate = _inputManager->update();

  if (_inputManager->isInputTriggered(InputCode::D)) {
    _debugState->toggleDebugMenuVisible();
  }

  return terminate;
}

void Game::update(double dt) {
  auto iter = _viewLayers.begin();
  for (; iter != _viewLayers.end(); iter++) {
    ViewLayer::shared_ptr layer = (*iter);
    layer->update(dt);
  }
}

void Game::render() {
  _rendererManager->render(_viewLayers.begin(), _viewLayers.end());
}

void Game::reset() { _inputManager->clearTriggeredInputs(); }

void Game::setScreenSize(HMM_Vec2 size) {
  _rendererManager->setScreenSize(size);
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

ViewFactory::shared_ptr Game::viewFactory() { return _viewFactory; }

FileManager::shared_ptr Game::fileManager() { return _fileManager; }

FontManager::shared_ptr Game::fontManager() { return _fontManager; }

SpriteManager::shared_ptr Game::spriteManager() { return _spriteManager; }

InputManager::shared_ptr Game::inputManager() { return _inputManager; }

Camera::shared_ptr Game::camera() { return _camera; }

DebugState::shared_ptr Game::debugState() { return _debugState; }

ViewLayer::shared_ptr Game::getViewLayer(int index) {
  return _viewLayers[index];
}

#pragma mark Protected Methods

LogCategory Game::logCategory() const { return LogCategory::core; }
} // namespace grumble
