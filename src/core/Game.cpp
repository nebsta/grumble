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
      _debugState(std::make_shared<DebugState>()) {}

Game::~Game() {}

#pragma mark Lifecycle Events

void Game::setup() {
  _spriteManager->setup();
  _fontManager->setup();
  _rendererManager->setup(_camera, _debugState);
  setupViewLayers();
}

void Game::setupViewLayers() {
  logInfo("Setting up view layers");
  for (int i = 0; i < MAX_VIEW_LAYERS; i++) {
    _viewLayers[i] = std::make_unique<ViewLayer>();
  }
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

  // updating the views
  auto iter = _viewLayers.begin();
  for (; iter != _viewLayers.end(); iter++) {
    (*iter)->update(dt);
  }

  // updating systems
  auto systemIter = _systems.begin();
  for (; systemIter != _systems.end(); systemIter++) {
    (*systemIter)->update(dt);
  }

  // updating the camera
  _camera->update(dt);
}

void Game::render(double t) {
  _rendererManager->prepareFrame(t);
  ViewLayer::iterator iter = _viewLayers.begin();
  for (; iter != _viewLayers.end(); iter++) {
    (*iter)->updateInstanceBuffer(_rendererManager, t);
  }
  _rendererManager->drawFrame(t);
}

void Game::reset() { _inputManager->clearTriggeredInputs(); }

#pragma mark Setters

void Game::registerSystem(System::unique_ptr system) {
  _systems.push_back(std::move(system));
}

void Game::addView(View::unique_ptr view, ViewLayerType layer) {
  logDebug("Adding view {} to layer {}", view->id(),
           ViewLayerType_toString(layer));
  _viewLayers[layer]->addView(std::move(view));
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

LogCategory Game::logCategory() const { return LogCategory::core; }
} // namespace grumble
