//
//  Game.cpp
//  grumble
//
//  Created by Benjamin Wallis on 17/07/2023.
//

#include "Game.hpp"

namespace grumble {
  Game::Game(ScreenManager *screenManager, View *rootView) : _screenManager(screenManager), _rootView(rootView) {
    
  }

  Game::~Game() {
    delete _screenManager;
    _screenManager = nullptr;
  }

  void Game::setup() {
    _screenManager->setup();
  }

  void Game::update(float dt) {
    _rootView->update(dt);
  }

  void Game::render() {
    _rootView->render();
  }
}
