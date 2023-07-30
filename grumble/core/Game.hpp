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
    Game(std::shared_ptr<RendererManager> rendererManager,
         std::shared_ptr<FileManager> fileManager,
         std::shared_ptr<SpriteManager> spriteManager,
         std::string mainFontFile);
    ~Game();
    
    void setup(float renderScale);
    
    void update(double dt);
    void render();
    
    std::shared_ptr<ViewFactory> viewFactory();
    std::shared_ptr<FileManager> fileManager();
    std::shared_ptr<FontManager> fontManager();
    std::shared_ptr<SpriteManager> spriteManager();
    std::shared_ptr<View> rootView();
    
  protected:
    LogCategory logCategory() override;
    
  private:
    std::shared_ptr<RendererManager> _rendererManager;
    std::shared_ptr<ViewFactory> _viewFactory;
    std::shared_ptr<FontManager> _fontManager;
    std::shared_ptr<FileManager> _fileManager;
    std::shared_ptr<SpriteManager> _spriteManager;
    
    std::shared_ptr<View> _rootView;
  };
}
