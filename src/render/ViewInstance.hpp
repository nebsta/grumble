#pragma once

#include "../util/HandmadeMath.h"
#include "../util/MathUtils.hpp"
#include <fmt/compile.h>

namespace grumble {
struct ViewInstance {
  HMM_Vec2 uv0;
  HMM_Vec2 uv1;
  HMM_Vec2 uv2;
  HMM_Vec2 uv3;
  HMM_Vec2 uvs;
  HMM_Vec2 uvo;
  HMM_Vec4 colx;
  HMM_Vec4 coly;
  HMM_Vec4 colz;
  HMM_Vec4 colw;

  std::string toString() {
    return fmt::format(
        "uv0: {}, uv1: {}, uv2: {}, uv3: {}, uvs: {}, uvo: {}, colx: "
        "{}, coly: {}, colz: {}, colw: {}",
        HMM_Vec2_toString(uv0), HMM_Vec2_toString(uv1), HMM_Vec2_toString(uv2),
        HMM_Vec2_toString(uv3), HMM_Vec2_toString(uvs), HMM_Vec2_toString(uvo),
        HMM_Vec4_toString(colx), HMM_Vec4_toString(coly),
        HMM_Vec4_toString(colz), HMM_Vec4_toString(colw));
  }
};

} // namespace grumble
