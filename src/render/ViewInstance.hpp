#pragma once

#include "../util/HandmadeMath.h"

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
  // HMM_Vec4 tint;
};
