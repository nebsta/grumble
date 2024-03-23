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
};

static std::string ViewInstance_toString(ViewInstance instance) {
  return fmt::format(
      "uv0: {}, uv1: {}, uv2{}, uv3{}, uvs: {}, uvo: {}, colx: "
      "{}, coly: {}, colz: {}, colw: {}",
      HMM_Vec2_toString(instance.uv0), HMM_Vec2_toString(instance.uv1),
      HMM_Vec2_toString(instance.uv2), HMM_Vec2_toString(instance.uv3),
      HMM_Vec2_toString(instance.uvs), HMM_Vec2_toString(instance.uvo),
      HMM_Vec4_toString(instance.colx), HMM_Vec4_toString(instance.coly),
      HMM_Vec4_toString(instance.colz), HMM_Vec4_toString(instance.colw));
}
} // namespace grumble
