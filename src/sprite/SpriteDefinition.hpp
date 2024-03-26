#pragma once

#include "SpriteRegion.hpp"
#include <vector>

#define EMPTY_SPRITE                                                           \
  {                                                                            \
    "", "", {0, 0}, {                                                          \
      {0, 0}, {0, 0}, {0, 0}, { 0, 0 }                                         \
    }                                                                          \
  }

namespace grumble {
struct SpriteDefinition {
public:
  typedef std::vector<SpriteDefinition> vector;

  std::string_view name;
  std::string_view atlas;
  HMM_Vec2 size;
  SpriteRegion region;

  std::string toString() const {
    return fmt::format("name: {}, atlas: {}, region: {}, size: {}", name, atlas,
                       region.toString(), HMM_Vec2_toString(size));
  }

  bool isEmpty() const { return name.size() == 0; }
};
} // namespace grumble
