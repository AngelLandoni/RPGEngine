//
//  texture.hpp
//  HitBox
//
//  Created by Angel Land on 4/6/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

// OpenGL
#include "../../../External/includes/Glew/glew.h"
#include "../../Utils/codeExtension.hpp"
#include "../../maths/rect.hpp"

NAMESPACE_BEGIN(GEngine);

class Texture{
protected:
  // Reference to texture on GPU
  unsigned int mId;
  short mWidth,mHeight,mBpp;
public:
  Texture();
  virtual ~Texture();
  void enable() const;
  void disable() const;
  
  inline Rect<float> getSize() const{
    return Rect<float>(mWidth,mHeight);
  }
  
protected:
  friend class TextureManager;
};

NAMESPACE_END(GEngine);

#endif /* texture_hpp */
