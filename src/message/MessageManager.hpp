//
//  MessageManager.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 10/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <functional>
#include <vector>
#include <map>
#include <string>

namespace grumble {
  typedef std::function<void()> BasicCallback;
  typedef std::vector<BasicCallback> CallbackList;

  class MessageManager {
    
  public:
    static MessageManager& instance() {
      static MessageManager instance;
      return instance;
    }
    
    void subscribe(std::string type, BasicCallback callback);
    void unsubscribe(std::string type, BasicCallback callback);
    
  private:
    std::map<std::string,CallbackList> _subscribers;
  };
}
