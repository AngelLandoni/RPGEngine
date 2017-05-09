//
//  scene.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 29/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp

#include <list>
#include <memory>

#include "../Utils/codeExtension.hpp"
#include "../Graphics/Rendering/renderer.hpp"
#include "../Graphics/Rendering/rendereable.hpp"
#include "../Graphics/OpenGL/shaderManager.hpp"
#include "basicCamera.hpp"

NAMESPACE_BEGIN(GEngine);

class Scene {
protected:
  BasicCamera* mCamera;
  std::list<Renderable*> mRendereables;
  Renderer mRenderer;
public:
  Scene();
  virtual ~Scene();
  
  inline void addObject(Renderable* object) {mRendereables.push_back(object);}
  inline void removeObject(Renderable* object) {mRendereables.remove(object);}
  inline void setCamera(BasicCamera* camera) {mCamera = camera;}
  
  void update();
};

NAMESPACE_END(GEngine);


#endif /* scene_hpp */
