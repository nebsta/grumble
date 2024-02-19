//
//  Game.hpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#pragma once

#include <chrono>
#include <string>
#include <memory>

#include "Object.hpp"

#include "../logging/Logger.hpp"

#include "../util/Time.hpp"

#include "../render/RendererManager.hpp"

#include "../sprite/SpriteManager.hpp"

#include "../font/FontManager.hpp"

#include "../ui/View.hpp"
#include "../ui/ViewFactory.hpp"

#include "../io/FileManager.hpp"

namespace grumble {
  class Game: public Object {
  public:
    typedef std::shared_ptr<Game> shared_ptr;
    
    Game(RendererManager::shared_ptr rendererManager,
         FileManager::shared_ptr fileManager,
         SpriteManager::shared_ptr spriteManager,
         FontManager::shared_ptr fontManager);
    ~Game();
    
    void setup(float renderScale);
    
    void update(double dt);
    void render();
    
    ViewFactory::shared_ptr viewFactory();
    FileManager::shared_ptr fileManager();
    FontManager::shared_ptr fontManager();
    SpriteManager::shared_ptr spriteManager();
    View::shared_ptr rootView();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    RendererManager::shared_ptr _rendererManager;
    ViewFactory::shared_ptr _viewFactory;
    FontManager::shared_ptr _fontManager;
    FileManager::shared_ptr _fileManager;
    SpriteManager::shared_ptr _spriteManager;
    
    View::shared_ptr _rootView;
  };
}
