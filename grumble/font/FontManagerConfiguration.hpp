//
//  FontManagerConfiguration.hpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#pragma once


namespace grumble {
  struct FontManagerConfiguration {
    typedef std::vector<std::string>::iterator FontIterator;
    
    std::filesystem::path fontPath;
    std::string mainFont;
    std::vector<std::string> fonts;
  };
}

