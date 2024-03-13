//
//  Game.hpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#pragma once

#include <memory>

#include "Camera.hpp"
#include "Object.hpp"

#include "../render/RendererManager.hpp"

#include "../sprite/SpriteManager.hpp"

#include "../font/FontManager.hpp"

#include "../ui/View.hpp"
#include "../ui/ViewFactory.hpp"

#include "../input/InputManager.hpp"
#include "../io/FileManager.hpp"

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

  void setup();
  void teardown();

  // main steps in the game loop
  bool input();           // collect any input. Return true if game should quit
  void update(double dt); // perform updates within the engine
  void render();          // render the frame
  void reset();           // reset everything before the next frame

  ViewFactory::shared_ptr viewFactory();
  FileManager::shared_ptr fileManager();
  FontManager::shared_ptr fontManager();
  SpriteManager::shared_ptr spriteManager();
  InputManager::shared_ptr inputManager();
  View::shared_ptr rootView();
  Camera::shared_ptr camera();

  void setScreenSize(HMM_Vec2 size);
  void setCameraPosition(HMM_Vec2 pos);
  void moveCameraPosition(HMM_Vec2 by);

protected:
  LogCategory logCategory() const override;

private:
  RendererManager::shared_ptr _rendererManager;
  ViewFactory::shared_ptr _viewFactory;
  FontManager::shared_ptr _fontManager;
  FileManager::shared_ptr _fileManager;
  SpriteManager::shared_ptr _spriteManager;
  InputManager::shared_ptr _inputManager;
  Camera::shared_ptr _camera;
  View::shared_ptr _rootView;
};
} // namespace grumble
