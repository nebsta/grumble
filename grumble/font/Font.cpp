//
//  Font.cpp
//  grumble
//
//  Created by Benjamin Wallis on 07/08/2023.
//

#include "Font.hpp"

namespace grumble {
  Font::Font(FT_Face face) :
    _face(face) {
    
  }
             
  Font::~Font() {
    
  }
}
