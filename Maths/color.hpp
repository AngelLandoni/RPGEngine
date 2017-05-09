//
//  color.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 14/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef color_h
#define color_h

#include <stdint.h>

#include "../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

typedef struct Color {
  float r,g,b,a;
  
  Color() {
    r = 0;
    g = 0;
    b = 0;
    a = 1;
  }
  
  Color(float _r, float _g, float _b, float _a = 1.0) {
    r = _r;
    g = _g;
    b = _b;
    a = _a;
  }
  
  Color(int _hex, float _alpha = 1.0) {
    setColor(_hex, _alpha);
  }
  
  inline void setColor(int _hex, float _alpha = 1.0) {
    r = ((_hex >> 16) & 0xFF) / 255.0;
    g = ((_hex >> 8) & 0xFF) / 255.0;
    b = (_hex & 0xFF) / 255.0;
    a = _alpha;
  }
}Color;

NAMESPACE_END(GEngine);

#endif /* color_h */
