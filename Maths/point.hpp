//
//  point.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 11/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef point_h
#define point_h

#include "../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

template<typename T>
struct Point {
  T x,y;
  Point(){}
  Point(T _x, T _y) {
    x = _x;
    y = _y;
  }
};

NAMESPACE_END(GEngine);

#endif /* point_h */
