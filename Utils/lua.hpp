//
//  lua.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef lua_hpp
#define lua_hpp

#include <iostream>
#include <string>

extern "C" {
  #include "lua.h"
  #include "lauxlib.h"
  #include "lualib.h"
}

#include "codeExtension.hpp"
#include "log.hpp"

#define LUA_INCORRECT_FILENAME "LUA: Incorrect file name."

NAMESPACE_BEGIN(GEngine);

class Lua {
  lua_State* mState;
public:
  Lua();
  virtual ~Lua();
  void executeCode(const std::string _code);
  void executeFile(const std::string _file);
};

NAMESPACE_END(GEngine);

#endif /* lua_hpp */
