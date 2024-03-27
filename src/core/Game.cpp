#include "Game.hpp"
#include <fmt/core.h>

namespace grumble {
Game::Game(RendererManager::shared_ptr rendererManager,
           FileManager::shared_ptr fileManager,
           SpriteManager::shared_ptr spriteManager,
           FontManager::shared_ptr fontManager,
           InputManager::shared_ptr inputManager,
           EditorState::shared_ptr editorState)
    : _rendererManager(rendererManager), _fileManager(fileManager),
      _spriteManager(spriteManager),
      _viewFactory(std::make_shared<ViewFactory>(fontManager)),
      _fontManager(fontManager), _inputManager(inputManager),
      _camera(std::make_shared<Camera>()), _frameInput(EMPTY_INPUT),
      _debugState(std::make_shared<DebugState>()), _editorState(editorState) {}

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
    ViewLayerType layerType = static_cast<ViewLayerType>(i);
    std::string id = ViewLayerType_toString(layerType);
    _viewLayers[i] = std::make_unique<ViewLayer>(id);
  }
}

void Game::teardown() { _rendererManager->teardown(); }

#pragma mark Game Loop

bool Game::input() {
  _frameInput = _inputManager->collect();
  if (_frameInput.shouldTerminate) {
    return true;
  }

  if (_inputManager->isInputTriggered(InputCode::D)) {
    _debugState->toggleDebugMenuVisible();
  }

  if (_inputManager->isInputTriggered(InputCode::E)) {
    _editorState->toggleActive();
  }

  return false;
}

void Game::update(double dt) {
  // updating the views
  for (auto &layer : _viewLayers) {
    layer->update(dt, _frameInput);
  }

  // updating systems
  for (auto &system : _systems) {
    system->update(dt);
  }

  // updating the camera
  _camera->update(dt);
  _frameInput.handled = false;
}

void Game::render(double t) {
  _rendererManager->prepareFrame(t);

  InstanceBufferCollection &collection =
      _rendererManager->instanceBufferCollection();
  for (auto &viewLayer : _viewLayers) {
    viewLayer->pushBuffer(collection, t);
  }
  _rendererManager->drawFrame(t);
}

void Game::reset() {
  _inputManager->reset();
  _rendererManager->reset();
}

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
