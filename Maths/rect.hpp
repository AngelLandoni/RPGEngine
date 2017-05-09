//
//  rect.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 11/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef rect_h
#define rect_h

#include "../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

template<typename T>
struct Rect {
  T width,height;
  Rect(){}
  Rect(T _width, T _height) {
    width = _width;
    height = _height;
  }
};

NAMESPACE_END(GEngine);

#endif /* rect_h */
