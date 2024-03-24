#pragma once

#include "../debug/DebugState.hpp"
#include "../font/FontManager.hpp"
#include "../input/InputManager.hpp"
#include "../io/FileManager.hpp"
#include "../render/RendererManager.hpp"
#include "../sprite/SpriteManager.hpp"
#include "../ui/ViewFactory.hpp"
#include "../ui/ViewLayer.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "System.hpp"
#include <memory>

namespace grumble {
class Game : public Object {
public:
  typedef std::shared_ptr<Game> shared_ptr;

  Game(RendererManager::shared_ptr rendererManager,
       FileManager::shared_ptr fileManager,
       SpriteManager::shared_ptr spriteManager,
       FontManager::shared_ptr fontManager,
       InputManager::shared_ptr inputManager);
  ~Game();

  // lifecycle methods
  void setup();
  void teardown();

  // main steps in the game loop
  bool input();           // collect any input. Return true if game should quit
  void update(double dt); // perform updates within the engine
  void render(double t);  // render the frame
  void reset();           // reset everything before the next frame

  // getters
  ViewFactory::shared_ptr viewFactory();
  FileManager::shared_ptr fileManager();
  FontManager::shared_ptr fontManager();
  SpriteManager::shared_ptr spriteManager();
  InputManager::shared_ptr inputManager();
  Camera::shared_ptr camera();
  DebugState::shared_ptr debugState();

  // setters
  void registerSystem(System::unique_ptr system);
  void addView(View::unique_ptr view, ViewLayerType layer);
  void setScreenSize(HMM_Vec2 size);

protected:
  LogCategory logCategory() const override;

private:
  bool _isSetup;

  RendererManager::shared_ptr _rendererManager;
  ViewFactory::shared_ptr _viewFactory;
  FontManager::shared_ptr _fontManager;
  FileManager::shared_ptr _fileManager;
  SpriteManager::shared_ptr _spriteManager;
  InputManager::shared_ptr _inputManager;
  Camera::shared_ptr _camera;
  DebugState::shared_ptr _debugState;
  ViewLayer::array _viewLayers;
  System::vector _systems;

  void setupViewLayers();
};
} // namespace grumble
