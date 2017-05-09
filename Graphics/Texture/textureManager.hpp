//
//  textureManager.hpp
//  HitBox
//
//  Created by Angel Land on 4/6/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef textureManager_hpp
#define textureManager_hpp

#include <list>
#include <string>

#include "../../../External/includes/Glew/glew.h"
#include "../../Utils/codeExtension.hpp"
#include "../../CustomFiles/tga.hpp"
#include "texture.hpp"

NAMESPACE_BEGIN(GEngine);

#define TextureManagerInstance TextureManager::getInstance()

/*
 TODO:
 Optimization problems, What happen if 2 animated
 sprites has the same frame? we need check it and
 do something about this, beacuse we will have
 the same image in GPU memory.
 */
class TextureManager{
    std::list<Texture*> mTextures;
public:
    enum Format { TGA,SI };
    static TextureManager& getInstance();
    Texture* createFromPixel(const unsigned short width,
                             const unsigned short height,
                             const unsigned short bpp,
                             const char* buffer);
    
    template<Format n, typename std::enable_if<n == Format::TGA>::type* = nullptr>
    inline Texture* load(const std::string _file) { return loadTGAimage(_file); }
private:
    TextureManager();
    virtual ~TextureManager();
    
    Texture* loadTGAimage(const std::string _file);
};

NAMESPACE_END(GEngine);

#endif /* textureManager_hpp */
