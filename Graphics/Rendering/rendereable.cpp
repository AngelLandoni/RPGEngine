//
//  rendereable.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "rendereable.hpp"

NAMESPACE_BEGIN(GEngine);

Renderable::Renderable() {

}

Renderable::~Renderable() {

}

void Renderable::bind() const {
    mMaterial->flushData();
    mMaterial->mProgram->submit(RENDEREABLE_SHADER_TRANSFORM_NAME, mTransform.getTransformation());
    mMaterial->enable();
}

void Renderable::unBind() const {
    mMaterial->disable();
}

NAMESPACE_END(GEngine)
