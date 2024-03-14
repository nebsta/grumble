#pragma once

#include "../core/Object.hpp"
#include "../ui/View.hpp"
#include <array>
#include <memory>
#include <vector>

#define MAX_VIEW_LAYERS 5

namespace grumble {
class ViewLayer : public Object {
public:
  typedef std::shared_ptr<ViewLayer> shared_ptr;
  typedef std::array<shared_ptr, MAX_VIEW_LAYERS> array;
  typedef array::iterator iterator;

  ViewLayer();
  ~ViewLayer();

  void addView(View::shared_ptr view);
  void update(double dt);

  View::iterator viewIteratorBegin();
  View::iterator viewIteratorEnd();

protected:
  LogCategory logCategory() const override;

private:
  std::vector<View::shared_ptr> _views;
};

} // namespace grumble
