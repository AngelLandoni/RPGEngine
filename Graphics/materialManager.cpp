//
//  materialManager.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/11/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#include "materialManager.hpp"

NAMESPACE_BEGIN(GEngine);

MaterialManager::MaterialManager() {

}

MaterialManager::~MaterialManager() {
    for (auto const& item : mMaterials)
        if (item.second != nullptr)
            delete item.second;
}

MaterialManager& MaterialManager::getInstance() {
    static MaterialManager instance;
    return instance;
}

Material* MaterialManager::create(const std::string name) {
    Material* newMaterial = new Material();
    mMaterials[name] = newMaterial;
    return newMaterial;
}

NAMESPACE_END(GEngine);