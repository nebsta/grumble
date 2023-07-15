//
//  Logger.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "Logger.hpp"

namespace grumble {
  void Logger::logMessage(std::string message) {
    std::cout << message << "\n";
  }

  void Logger::logMessage(std::string message, const char* vs...) {
    
    // todo need to implement this fully
    
    int count = sizeof(vs);
    std::string formattedString;
    std::stringstream stream;
    
    for (int i = 0; i < count; i++) {
      stream << "{" << i << "}";
    }
    
    std::cout << formattedString << "\n";
  }

  void Logger::logError(std::string error) {
    std::cerr << "Error: " << error << "\n";
  }
}
