//
//  ViewFactory.hpp
//  grumble
//
//  Created by Benjamin Wallis on 23/07/2023.
//

#pragma once

#include <memory>

#include "../core/Object.hpp"

#include "../ui/View.hpp"

#include "../font/FontManager.hpp"

namespace grumble {
class ViewFactory : public Object {
public:
  typedef std::shared_ptr<ViewFactory> shared_ptr;

  ViewFactory(FontManager::shared_ptr fontManager);

  View::shared_ptr
  createView(glm::vec2 position = VECTOR_EMPTY, glm::vec2 size = {0.0, 0.0},
             TransformOrigin origin = TransformOrigin::TopLeft);

private:
  FontManager::shared_ptr _fontManager;
  uint32_t _runningInstanceId;

  uint32_t generateInstanceId();
};
} // namespace grumble
