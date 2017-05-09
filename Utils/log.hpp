//
//  log.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef log_hpp
#define log_hpp

#include <iostream>
#include <string>

#include "codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

enum LogType{
  INFO,
  NORMAL,
  WARNING,
  ERROR
};

void log(const std::string _text, const LogType _type);

NAMESPACE_END(GEngine);

#endif /* log_hpp */
