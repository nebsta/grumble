#include "Object.hpp"

namespace grumble {
Object::Object(std::string_view id) : _id(id) {}

Object::~Object() {}

const std::string Object::toString() const {
  return fmt::format("id: {}", _id);
}

LogCategory Object::logCategory() const { return LogCategory::none; }

const std::string Object::id() const { return _id; }

} // namespace grumble
