//
//  renderer.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 14/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef renderer_hpp
#define renderer_hpp

#define GL_GLEXT_PROTOTYPES 1

#include <iostream>

#include <deque>

#include "../../../External/includes/Glew/glew.h"
#include "../../Utils/codeExtension.hpp"

#include "rendereable.hpp"

NAMESPACE_BEGIN(GEngine);

class Renderer {
protected:
  std::deque<const Renderable*> mRenderQueue;
public:
  Renderer();
  virtual ~Renderer();
  virtual void submit(const Renderable& renderable);
  virtual void flush();
};

NAMESPACE_END(GEngine);

#endif /* renderer_hpp */
