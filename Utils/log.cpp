//
//  log.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "log.hpp"

NAMESPACE_BEGIN(GEngine);

void log(const std::string _text, const LogType _type) {
  if(_type == INFO) {
    std::cout<<"[INFO] ";
    std::cout.flush();
  }
  if(_type == NORMAL) {
    std::cout<<"[NORMAL] ";
    std::cout.flush();
  }
  if(_type == WARNING) {
    std::cout<<"[WARNING] ";
    std::cout.flush();
  }
  if(_type == ERROR) {
    std::cout<<"[ERROR] ";
    std::cout.flush();
  }
  std::cout<<_text<<std::endl;
  std::cout.flush();
}


NAMESPACE_END(GEngine);
