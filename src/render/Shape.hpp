#pragma once
#include <vector>

struct Vertex {
  float x, y, z;
};

struct Shape {
  int id;
  std::vector<Vertex> vertices;
  std::vector<int> indices;
};

#define SHAPE_SQUARE                                                           \
  {                                                                            \
    0,                                                                         \
        {{-0.5, -0.5, 0.0},                                                    \
         {-1.0, 1.0, 0.0},                                                     \
         {1.0, 1.0, 0.0},                                                      \
         {1.0, -1.0, 0.0}},                                                    \
    {                                                                          \
      0, 1, 2, 3, 0, 2                                                         \
    }                                                                          \
  }
