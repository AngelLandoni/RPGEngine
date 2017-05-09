//
//  model.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/14/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#ifndef model_hpp
#define model_hpp


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
#include "../../OpenGL/Buffers/vertexArray.hpp"

#include "modelManager.hpp"

NAMESPACE_BEGIN(GEngine);

class Model {
protected:
    VertexArray mVertexArray;
    IndexBuffer mIndexBuffer;
public:
    Model();
    Model(const RawModel rawModel);
    virtual ~Model();
    
    void setRawModel(const RawModel rawModel);
public:
    friend class Renderer;
};

NAMESPACE_END(GEngine);

#endif /* model_hpp */
