//
//  basicCamera.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 23/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef basicCamera_hpp
#define basicCamera_hpp

#include "../../External/includes/glm/glm.hpp"
#include "../../External/includes/glm/vec3.hpp"
#include "../../External/includes/glm/mat4x4.hpp"
#include "../../External/includes/glm/gtc/matrix_transform.hpp"
#include "../../External/includes/glm/gtx/transform.hpp"

#include "../Utils/codeExtension.hpp"

#include "../Maths/transform.hpp"

#include "../Graphics/displayManager.hpp"

#include "../Managers/inputManager.hpp"

NAMESPACE_BEGIN(GEngine);

class BasicCamera {
protected:
  glm::mat4 mPerspective;
  glm::mat4 mView;
  glm::vec3 mPosition;
  glm::vec3 mViewPoint;
  Rect<int> mSize;
public:
  BasicCamera();
  virtual ~BasicCamera();
  
  void init();
  virtual void update();
  
  inline void setPosition(const glm::vec3 position) { mPosition = position; }
  inline void setViewPoint(const glm::vec3 viewPoint) { mViewPoint = viewPoint; }
  
  inline const glm::mat4 getProjection() const { return mPerspective; }
  inline const glm::mat4 getView() const { return mView; }
};

NAMESPACE_END(GEngine);

#endif /* basicCamera_hpp */
