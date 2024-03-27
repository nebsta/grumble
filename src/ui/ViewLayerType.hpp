#pragma once
#include <string>

#define MAX_VIEW_LAYERS 9

namespace grumble {
enum ViewLayerType {
  BACKGROUND_1 = 0,
  BACKGROUND_2 = 1,
  BACKGROUND_3 = 2,
  FOREGROUND_1 = 3,
  FOREGROUND_2 = 4,
  FOREGROUND_3 = 5,
  UI_1 = 6,
  UI_2 = 7,
  UI_3 = 8,
};

static std::string ViewLayerType_toString(ViewLayerType type) {
  switch (type) {
  case BACKGROUND_1:
    return "BACKGROUND_1";
  case BACKGROUND_2:
    return "BACKGROUND_2";
  case BACKGROUND_3:
    return "BACKGROUND_3";
  case FOREGROUND_1:
    return "FOREGROUND_1";
  case FOREGROUND_2:
    return "FOREGROUND_2";
  case FOREGROUND_3:
    return "FOREGROUND_3";
  case UI_1:
    return "UI_1";
  case UI_2:
    return "UI_2";
  case UI_3:
    return "UI_3";
  }
}
} // namespace grumble
