//
//  SpriteManagerConfig.hpp
//  grumble
//
//  Created by Benjamin Wallis on 04/08/2023.
//

#pragma once

namespace grumble {
  struct SpriteManagerConfiguration {
    typedef std::vector<std::string>::iterator AtlasIterator;
    
    std::filesystem::path atlasPath;
    std::vector<std::string> atlases;
  };
}
