//
//  Touch.hpp
//  grumble
//
//  Created by Benjamin Wallis on 13/01/2022.
//

#ifndef Touch_h
#define Touch_h

#include <glm/glm.hpp>

#include "MathConstants.h"

namespace grumble {
    struct Touch  {
        int id;
        glm::vec2 location;
    };

    const Touch TouchEmpty = {-1, VECTOR_EMPTY};

    inline std::string touchToString(Touch touch) {
        std::stringstream stream;
        stream << "Touch { id: " << touch.id << " loc: " << touch.location.x << ", " << touch.location.y << " }";
        return stream.str();
    }
}

#endif /* Touch_hpp */
