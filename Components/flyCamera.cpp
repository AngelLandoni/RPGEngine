//
//  flyCamera.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/14/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#include "flyCamera.hpp"

NAMESPACE_BEGIN(GEngine);

FlyCamera::FlyCamera() :
isAttached(true),
mHorizontalAngle(0),
mVerticalAngle(0),
mSpeed(0.05)
{
    InputManagerIntance.hideMouse();
    BasicCamera::BasicCamera();
}

FlyCamera::~FlyCamera() {
    BasicCamera::~BasicCamera();
}

void FlyCamera::update() {
    Point<int> mousePosition = InputManagerIntance.getMousePosition();
    
    if (isAttached) {
        mHorizontalAngle += 0.1 * float( DisplayManagerInstance.getSize().width/2 - mousePosition.x ) / 50;
        mVerticalAngle += 0.1 * float( DisplayManagerInstance.getSize().height/2 - mousePosition.y ) / 50;
        InputManagerIntance.setMousePosition(Point<int>(DisplayManagerInstance.getSize().width/2,DisplayManagerInstance.getSize().height/2));
    }
    
    glm::vec3 direction(cos(mVerticalAngle) * sin(mHorizontalAngle),
                        sin(mVerticalAngle),
                        cos(mVerticalAngle) * cos(mHorizontalAngle));
    
    glm::vec3 right = glm::vec3(sin(mHorizontalAngle - 3.14f/2.0f),
                                0,
                                cos(mHorizontalAngle - 3.14f/2.0f));
  
    std::cout<<direction.x<<direction.y<<direction.z<<std::endl;
    std::cout.flush();
    
    
    if (InputManagerIntance.getKeyState('w')) mPosition += direction * mSpeed;
    if (InputManagerIntance.getKeyState('s')) mPosition -= direction *  mSpeed;
    if (InputManagerIntance.getKeyState('a')) mPosition -= right *  mSpeed;
    if (InputManagerIntance.getKeyState('d')) mPosition += right *  mSpeed;
    // 32 = space
    if (InputManagerIntance.getKeyState(32)) mPosition.y += mSpeed;
    
    setViewPoint(direction+mPosition);
    
    BasicCamera::update();
}

void FlyCamera::attach() {
    isAttached = true;
    InputManagerIntance.hideMouse();
}

void FlyCamera::unAttach() {
    isAttached = false;
    InputManagerIntance.showMouse();
}

NAMESPACE_END(GEngine);