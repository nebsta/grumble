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

  void update(double dt);
  void render();

  ViewFactory::shared_ptr viewFactory();
  FileManager::shared_ptr fileManager();
  FontManager::shared_ptr fontManager();
  SpriteManager::shared_ptr spriteManager();
  InputManager::shared_ptr inputManager();
  View::shared_ptr rootView();
  Camera::shared_ptr camera();

  void setScreenSize(HMM_Vec2 size);
  void setCameraPosition(HMM_Vec2 pos);

protected:
  LogCategory logCategory() override;

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
