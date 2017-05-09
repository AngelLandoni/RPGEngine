//
//  material.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/8/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#ifndef material_hpp
#define material_hpp

#include <iostream>
#include <map>

#include "../Utils/codeExtension.hpp"
#include "OpenGL/shader.hpp"
#include "Texture/texture.hpp"

NAMESPACE_BEGIN(GEngine);

#define MATERIAL_PROPERTY_OPACITY "opacity"

class Material {
public:
    enum TextureType { DIFFUSE,COUNT };
protected:
    std::map<TextureType,Texture*> mTextures;
    Shader* mProgram;
    float mOpacity;
public:
    Material();
    virtual ~Material();
    
    void enable() const;
    void disable() const;
    
    template<TextureType n, typename std::enable_if<n == TextureType::DIFFUSE>::type* = nullptr>
    inline void setTexture(Texture* texture) { mTextures[TextureType::DIFFUSE] = texture; }
    inline void setShader(Shader* shader) { mProgram = shader; }
    inline void setOpacity(const float opacity) { mOpacity = opacity; }
protected:
    void flushData();
public:
    friend class Renderer;
    friend class Renderable;
};

NAMESPACE_END(GEngine);

#endif /* material_hpp */
