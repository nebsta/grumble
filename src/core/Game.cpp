//
//  Game.cpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#include "Game.hpp"

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
  _viewLayers[0] = std::make_shared<ViewLayer>();
  _viewLayers[1] = std::make_shared<ViewLayer>();
  _viewLayers[2] = std::make_shared<ViewLayer>();
  _viewLayers[3] = std::make_shared<ViewLayer>();
  _viewLayers[4] = std::make_shared<ViewLayer>();
}

Game::~Game() {}

#pragma mark Lifecycle Events

void Game::setup() {
  _spriteManager->setup();
  _fontManager->setup();
  _rendererManager->setup(_camera, _debugState);
}

void Game::teardown() { _rendererManager->teardown(); }

#pragma mark Game Loop

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

  auto systemIter = _systems.begin();
  for (; systemIter != _systems.end(); systemIter++) {
    (*systemIter)->update(dt);
  }

  _camera->update(dt);
}

void Game::render(double t) {
  _rendererManager->render(_viewLayers.begin(), _viewLayers.end(), t);
}

void Game::reset() { _inputManager->clearTriggeredInputs(); }

#pragma mark Setters

void Game::registerSystem(System::unique_ptr system) {
  _systems.push_back(std::move(system));
}

void Game::setScreenSize(HMM_Vec2 size) {
  _rendererManager->setScreenSize(size);
}

#pragma mark Getters

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

LogCategory Game::logCategory() const { return LogCategory::core; }
} // namespace grumble
