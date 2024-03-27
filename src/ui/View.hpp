#pragma once

#include "../core/Object.hpp"
#include "../render/InstanceBufferCollection.hpp"
#include <memory>

namespace grumble {
class View : public Object {
public:
  typedef std::unique_ptr<View> unique_ptr;
  typedef std::vector<unique_ptr> unique_vector;
  typedef unique_vector::iterator unique_iterator;

  View(const std::string &id);
  virtual ~View() = default;

  virtual void update(double dt) = 0;
  virtual void pushBuffer(InstanceBufferCollection &collection, double t) = 0;
  bool tryHandleTouch(HMM_Vec2 position);

  void setIsInteractive(bool isInteractive);
  bool isInteractive() const;

protected:
  virtual bool tryHandleTouchInternal(HMM_Vec2 position) = 0;

private:
  bool _isInteractive;
};
} // namespace grumble
