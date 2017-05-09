//
//  transform.hpp
//  HitBox
//
//  Created by Angel Land on 7/6/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef transform_hpp
#define transform_hpp

#include "../../External/includes/glm/vec3.hpp"
#include "../../External/includes/glm/mat4x4.hpp"
#include "../../External/includes/glm/gtx/transform.hpp"
#include "../../External/includes/glm/gtc/matrix_transform.hpp"
#include "../../External/includes/glm/gtx/transform.hpp"

#include "../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

typedef struct Transform{
  glm::vec3 position;
  glm::vec3 scale;
  glm::vec4 angle;
  
  Transform():
  position({0.0,0.0,0.0}),
  scale({1.0,1.0,1.0}),
  angle({0.0,1.0,1.0,1.0})
  {}
  
  inline glm::mat4 getTransformation() const{
    return glm::translate( position ) *
           glm::rotate( angle.x,glm::vec3( angle.y,angle.z,angle.w ) ) *
           glm::scale( scale );
  }
}Transform;

NAMESPACE_END(GEngine);

#endif /* transform_hpp */
