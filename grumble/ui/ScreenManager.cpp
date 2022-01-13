//
//  ScreenManager.cpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#include "ScreenManager.hpp"

template<typename T>
void ScreenManager::initialize() {
    
}

const ScreenHandler& ScreenManager::screenHandler() {
    return *_screenHandler;
}

float ScreenManager::screenWidth() const {
    return _screenHandler->screenWidth();
}

float ScreenManager::screenHeight() const {
    return _screenHandler->screenHeight();
}
