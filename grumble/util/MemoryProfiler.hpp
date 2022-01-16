//
//  MemoryProfiler.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 06/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#ifndef MemoryProfiler_hpp
#define MemoryProfiler_hpp

#include <stdio.h>
#include <iostream>
#include <queue>

#define USAGE_WINDOW_SIZE 500

namespace grumble {
    class MemoryProfiler {
        
    public:
        void memoryAllocated(const size_t& size);
        void memoryFreed(const size_t& size);
        
    private:
        int _memoryUsed;
        
        void updateUsageWindow();
    };
}

#endif /* MemoryProfiler_hpp */
