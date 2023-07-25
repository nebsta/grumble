//
//  Label.hpp
//  grumble
//
//  Created by Benjamin Wallis on 25/07/2023.
//

#pragma once

#include "View.hpp"

namespace grumble {
  class Label: public View {
  public:
    Label();
    Label(std::string text);
    ~Label();
    
  private:
    std::string _text;
  };
}
