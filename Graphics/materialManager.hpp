//
//  materialManager.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/11/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#ifndef materialManager_hpp
#define materialManager_hpp

#include <iostream>
#include <map>

#include "../Utils/codeExtension.hpp"
#include "material.hpp"

NAMESPACE_BEGIN(GEngine);

#define MaterialManagerInstance MaterialManager::getInstance()

class MaterialManager {
protected:
    std::map<std::string,Material*> mMaterials;
    Shader* mProgram;
public:
    static MaterialManager& getInstance();
    Material* create(const std::string name);
private:
    MaterialManager();
    virtual ~MaterialManager();
};

NAMESPACE_END(GEngine);

#endif /* materialManager_hpp */
