//
//  basicCamera.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 23/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "basicCamera.hpp"

NAMESPACE_BEGIN(GEngine);

BasicCamera::BasicCamera():
mPosition(glm::vec3(0,0,0)),
mViewPoint(glm::vec3(0,0,0)) {

}

BasicCamera::~BasicCamera() {
  
}

void BasicCamera::init() {
  mSize = DisplayManagerInstance.getSize();
  mPerspective = glm::perspective(glm::radians(60.0f), (float)(mSize.width/mSize.height), 0.1f, 1000.0f);
  mView = glm::lookAt(mPosition, mViewPoint, glm::vec3(0,1,0));
}

void BasicCamera::update() {
  mView = glm::lookAt(mPosition, mViewPoint, glm::vec3(0,1,0));
}

NAMESPACE_END(GEngine);
