#pragma once

#include <string>
namespace grumble {
enum GridResolution { Small = 0, Medium = 1, Large = 2 };

static std::string GridResolution_to_string(GridResolution resolution) {
  switch (resolution) {
  case GridResolution::Small:
    return "Small";
  case GridResolution::Medium:
    return "Medium";
  case GridResolution::Large:
    return "Large";
  }
}
} // namespace grumble
