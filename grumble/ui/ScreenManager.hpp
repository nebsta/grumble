//
//  ScreenManager.hpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#ifndef ScreenManager_hpp
#define ScreenManager_hpp

#include <stdio.h>
#include <memory>

#include "ScreenHandler.hpp"

class ScreenManager {
public:
    
    static ScreenManager& instance() {
        static ScreenManager instance;
        return instance;
    }
    
    template<typename T>
    void initialize();
    
    const ScreenHandler& screenHandler();
    
    float screenHeight() const;
    float screenWidth() const;
    
private:
    ScreenManager();
    ~ScreenManager();
    
    std::unique_ptr<ScreenHandler> _screenHandler;
};

#endif /* ScreenManager_hpp */
