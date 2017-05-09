//
//  material.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/8/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#include "material.hpp"

NAMESPACE_BEGIN(GEngine);

Material::Material() :
mOpacity(1)
{
}

Material::~Material() {

}

void Material::enable() const {
    // Add diferetns kind of textures.
    if (mTextures.at(TextureType::DIFFUSE) != nullptr) mTextures.at(TextureType::DIFFUSE)->enable();
}

void Material::disable() const {
    // Add diferetns kind of textures.
    if (mTextures.at(TextureType::DIFFUSE) != nullptr) mTextures.at(TextureType::DIFFUSE)->disable();
}

void Material::flushData() {
    mProgram->submit(MATERIAL_PROPERTY_OPACITY, mOpacity);
}


NAMESPACE_END(GEngine)