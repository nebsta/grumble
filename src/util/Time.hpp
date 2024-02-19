//
//  Time.hpp
//  grumble
//
//  Created by Benjamin Wallis on 19/07/2023.
//

#pragma once

#import <chrono>
#import <string>
#include <iomanip>
#include <sstream>

typedef std::chrono::duration<float, std::milli> DurationMilliseconds;
typedef std::chrono::duration<float> DurationSeconds;

namespace grumble {
  struct Time {
  public:
    static std::string timestampToString(std::chrono::system_clock::time_point tp);
    static std::string nowString();
  };
}
