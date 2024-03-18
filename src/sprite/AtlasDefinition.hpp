#pragma once

#include <map>
#include <string>

namespace grumble {
struct AtlasDefinition {
  typedef std::vector<AtlasDefinition> vector;

  std::string name;
};
} // namespace grumble
