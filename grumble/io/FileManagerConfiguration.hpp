//
//  FileManagerConfiguration.hpp
//  grumble
//
//  Created by Benjamin Wallis on 22/08/2023.
//

#pragma once

#include <filesystem>

namespace grumble {
  struct FileManagerConfiguration {
    std::filesystem::path rootReadPath;
    std::filesystem::path rootWritePath;
  };
}
