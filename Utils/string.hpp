//
//  string.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 6/11/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef string_hpp
#define string_hpp

#include <vector>
#include <string>

#include "codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

std::vector<std::string> string_parse(const std::string _buffer, const char _token);

NAMESPACE_END(GEngine);

#endif /* string_hpp */
