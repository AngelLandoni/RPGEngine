//
//  rendereable.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef rendereable_hpp
#define rendereable_hpp

#include "../../../External/includes/glm/vec2.hpp"
#include "../../../External/includes/glm/vec3.hpp"

#include "../../../External/includes/Glew/glew.h"
#include "../../Utils/codeExtension.hpp"

#include "../../Maths/transform.hpp"

#include "../OpenGL/Buffers/buffer.hpp"
#include "../OpenGL/Buffers/indexBuffer.hpp"
#include "../OpenGL/Buffers/vertexArray.hpp"
#include "../OpenGL/shader.hpp"

#include "../Texture/texture.hpp"

#include "../material.hpp"

#include "Model/modelManager.hpp"
#include "Model/model.hpp"

NAMESPACE_BEGIN(GEngine);

#define RENDEREABLE_SHADER_TRANSFORM_NAME "transform"

class Renderable {
protected:
    Transform mTransform;
    Material* mMaterial;
    Model* mModel;
    // TODO: Change public by protected.
public:
    Renderable();
    virtual ~Renderable();
    
    // Inline
    inline void setPosition(const glm::vec3 position) { mTransform.position = position; }
    inline void setSize(const glm::vec3 scale) { mTransform.scale = scale; }
    inline void setRotation(const glm::vec4 rotation) { mTransform.angle = rotation; }
    
    inline void setModel(Model* model) { mModel = model; }
    inline void setMaterial(Material* material) { mMaterial = material; }
protected:
    void bind() const;
    void unBind() const;
public:
    friend class Renderer;
    friend class Scene;
};

NAMESPACE_END(GEngine);

#endif /* rendereable_hpp */
