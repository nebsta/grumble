//
//  TransformOrigin.hpp
//  grumble
//
//  Created by Benjamin Wallis on 24/07/2023.
//

#pragma once

#include <fmt/compile.h>
namespace grumble {
enum TransformOrigin {
  TopLeft,
  Top,
  TopRight,
  Left,
  Center,
  Right,
  BottomLeft,
  Bottom,
  BottomRight
};

static const std::string TransformOrigin_toString(TransformOrigin origin) {
  switch (origin) {
  case TopLeft:
    return "TopLeft";
  case Top:
    return "Top";
  case TopRight:
    return "TopRight";
  case Left:
    return "Left";
  case Center:
    return "Center";
  case Right:
    return "Right";
  case BottomLeft:
    return "BottomLeft";
  case Bottom:
    return "Bottom";
  case BottomRight:
    return "BottomRight";
  }
}
} // namespace grumble
