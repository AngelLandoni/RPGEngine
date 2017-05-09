//
//  lua.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "lua.hpp"

NAMESPACE_BEGIN(GEngine);

Lua::Lua() {
  // Allocate a new state;
  mState = luaL_newstate();
  // Using lua libs.
  luaL_openlibs(mState);
}

Lua::~Lua() {
  lua_close(mState);
}

void Lua::executeCode(const std::string _code) {
  
}

void Lua::executeFile(const std::string _file) {
  if(_file == ""){
    log(LUA_INCORRECT_FILENAME, LogType::WARNING);
    return;
  }
  if(luaL_dofile(mState, _file.c_str())) {
    std::cout<<"LUA: "<<lua_tostring(mState, -1)<<std::endl;
    std::cout.flush();
  }
}

NAMESPACE_END(GEngine);
