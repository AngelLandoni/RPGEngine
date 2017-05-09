//
//  flyCamera.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/14/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#ifndef flyCamera_hpp
#define flyCamera_hpp

#include "../Managers/inputManager.hpp"

#include "basicCamera.hpp"

NAMESPACE_BEGIN(GEngine);

class FlyCamera : public BasicCamera {
protected:
    float mHorizontalAngle;
    float mVerticalAngle;
    float mSpeed;
    bool isAttached;
public:
    FlyCamera();
    virtual ~FlyCamera();
    
    void update() override;
    void attach();
    void unAttach();
};

NAMESPACE_END(GEngine);

#endif /* flyCamera_hpp */
