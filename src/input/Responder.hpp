#pragma once

namespace grumble {
typedef void (*touch_callback)();

struct Responder {
  touch_callback onTouchDown;
  touch_callback onTouchUp;
};
} // namespace grumble
