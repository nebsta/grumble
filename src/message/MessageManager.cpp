//
//  MessageManager.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#include "MessageManager.hpp"

namespace grumble {
  typedef CallbackList::iterator CallbackIterator;

  void MessageManager::subscribe(std::string type, BasicCallback callback) {
    CallbackList list = _subscribers[type];
    list.push_back(callback);
  }

  void MessageManager::unsubscribe(std::string type, BasicCallback callback) {
    CallbackList list = _subscribers[type];
    
    //    CallbackIterator pos = std::find(list.begin(), list.end(), callback);
    //    list.erase(pos);
  }
}
