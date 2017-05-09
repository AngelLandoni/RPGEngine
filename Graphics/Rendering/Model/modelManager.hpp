//
//  modelManager.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 30/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef modelManager_hpp
#define modelManager_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <map>

#include "../../../../External/includes/glm/vec3.hpp"

#include "../../../Utils/codeExtension.hpp"
#include "../../../Utils/string.hpp"
#include "../../OpenGL/Buffers/buffer.hpp"
#include "../../OpenGL/Buffers/indexBuffer.hpp"

NAMESPACE_BEGIN(GEngine);

#define ModelLoaderInstance ModelLoader::getInstance()

#define MODELMANAGER_OBJ_TOKEN_SPACE ' '
#define MODELMANAGER_OBJ_TOKEN_SLASH '/'
#define MODELMANAGER_OBJ_TOKEN_VERTEX "v"
#define MODELMANAGER_OBJ_TOKEN_TEXTURE "vt"
#define MODELMANAGER_OBJ_TOKEN_NORMAL "vn"
#define MODELMANAGER_OBJ_TOKEN_FACE "f"

#define MODELMANAGER_OBJ_X_COMPONENT 1
#define MODELMANAGER_OBJ_Y_COMPONENT 2
#define MODELMANAGER_OBJ_Z_COMPONENT 3

typedef struct RawModel {
    Buffer vertices;
    Buffer uvs;
    Buffer normals;
    IndexBuffer index;
}RawModel;

class ModelLoader {
    std::map <std::string,RawModel> mModels;
public:
    // Differents formats supported by the engine.
    enum Format { OBJ, SOMEFORMAT };
    // This method returns a singleton instance.
    static ModelLoader& getInstance();
    // This method returns the raw model from a
    // OBJ file.
    template<Format n, typename std::enable_if<n == Format::OBJ>::type* = nullptr>
    inline RawModel load(const std::string file) { return loadOBJ(file); }
private:
    ModelLoader();
    virtual ~ModelLoader();
    
    RawModel loadOBJ(const std::string file);
};

NAMESPACE_END(GEngine);

#endif /* modelManager_hpp */
