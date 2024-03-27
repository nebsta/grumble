#include "View.hpp"

namespace grumble {
View::View(const std::string &id) : Object(id) {}

bool View::isInteractive() const { return _isInteractive; }

void View::setIsInteractive(bool isInteractive) {
  _isInteractive = isInteractive;
}

} // namespace grumble
