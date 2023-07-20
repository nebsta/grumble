//
//  Time.cpp
//  grumble
//
//  Created by Benjamin Wallis on 20/07/2023.
//

#include "Time.hpp"

namespace grumble {
  std::string Time::timestampToString(std::chrono::system_clock::time_point tp) {
    auto now = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::gmtime(&tt);
    std::stringstream stream;
    stream << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return stream.str();
  }

  std::string Time::nowString() {
    auto now = std::chrono::system_clock::now();
    return Time::timestampToString(now);
  }
}
