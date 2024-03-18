//
//  SpriteManagerConfig.hpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#pragma once
#include <filesystem>
#include <string_view>
#include <vector>

namespace grumble {
struct SpriteManagerConfiguration {
  std::filesystem::path atlasPath;
  std::vector<std::string_view> preloadedAtlases;
};
} // namespace grumble
