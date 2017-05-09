//
//  scene.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 29/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "scene.hpp"

NAMESPACE_BEGIN(GEngine);

Scene::Scene() {
    
}

Scene::~Scene() {
    
}

void Scene::update() {
    // Update shaders with the projection
    ShaderManagerInstance.updateProjectionAndView(mCamera);
    
    for (Renderable* object : mRendereables) {
        mRenderer.submit(*object);
    }
    
    mRenderer.flush();
    mCamera->update();
}

NAMESPACE_END(GEngine);
