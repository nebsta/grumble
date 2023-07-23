//
//  Shapes.hpp
//  grumble
//
//  Created by Benjamin Wallis on 22/07/2023.
//

#pragma once

#define MAX_VERTICES 50

namespace grumble {
  struct Vertex {
    glm::vec2 position;
    glm::vec2 textCoord;
  };

  struct Mesh {
    Vertex vertices[MAX_VERTICES];
    int vertexCount;
  };

  class Shapes {
  public:
    inline static Mesh Square = {
      {
        {glm::vec2(0.0f,1.0f),glm::vec2(0.0f,1.0f)},
        {glm::vec2(0.0f,0.0f),glm::vec2(0.0f,0.0f)},
        {glm::vec2(1.0f,1.0f),glm::vec2(1.0f,1.0f)},
        {glm::vec2(1.0f,0.0f),glm::vec2(1.0f,0.0f)}
      }, 4
    };
  };
}
