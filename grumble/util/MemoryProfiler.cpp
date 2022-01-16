//
//  MemoryProfiler.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 06/01/2022.
//  Copyright © 2022 The Caffeinated Coder. All rights reserved.
//

#include "MemoryProfiler.hpp"

static grumble::MemoryProfiler profiler;

void* operator new(size_t size) {
    
//    std::cout << "Allocating " << size << " bytes\n";
    profiler.memoryAllocated(size);
    
    return malloc(size);
}

void operator delete(void* memory, size_t size) noexcept {
    
//    std::cout << "Freeing " << size << " bytes\n";
    profiler.memoryFreed(size);
    
    free(memory);
}

namespace grumble {

    void MemoryProfiler::memoryFreed(const size_t &size) {
        _memoryUsed -= size;
    }

    void MemoryProfiler::memoryAllocated(const size_t &size) {
        _memoryUsed += size;
    }
}
