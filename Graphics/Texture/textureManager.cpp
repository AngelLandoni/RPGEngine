//
//  textureManager.cpp
//  HitBox
//
//  Created by Angel Land on 4/6/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "textureManager.hpp"

NAMESPACE_BEGIN(GEngine);

TextureManager& TextureManager::getInstance(){
    static TextureManager instance;
    return instance;
}

// MARK: - Private methods

TextureManager::TextureManager(){}

TextureManager::~TextureManager(){
    for(Texture* item : mTextures){
        if(item == nullptr) continue;
        delete item;
        item = nullptr;
    }
}

Texture* TextureManager::createFromPixel( const unsigned short _width,
                                         const unsigned short _height,
                                         const unsigned short _bpp,
                                         const char* _buffer ){
    Texture* newTexture = new Texture();
    
    glGenTextures(1, &newTexture->mId);
    glBindTexture(GL_TEXTURE_2D, newTexture->mId);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    newTexture->mWidth = _width;
    newTexture->mHeight = _height;
    newTexture->mBpp = _bpp;
    
    if(newTexture->mBpp == 32)
        glTexImage2D(GL_TEXTURE_2D ,
                     0,
                     GL_RGBA,
                     newTexture->mWidth,
                     newTexture->mHeight,
                     0,
                     GL_RGBA,
                     GL_UNSIGNED_BYTE,
                     _buffer);
    else if(newTexture->mBpp == 24)
        glTexImage2D( GL_TEXTURE_2D ,
                     0,
                     GL_RGB,
                     newTexture->mWidth,
                     newTexture->mHeight,
                     0,
                     GL_RGB,
                     GL_UNSIGNED_BYTE,
                     _buffer);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    return newTexture;
    
}

Texture* TextureManager::loadTGAimage(const std::string _file){
    Texture* newTexture = new Texture();
    
    glGenTextures(1, &newTexture->mId);
    glBindTexture(GL_TEXTURE_2D, newTexture->mId);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    TGA_FILE image = tga_load(_file);
    
    memcpy(&newTexture->mWidth, image.width, 2);
    memcpy(&newTexture->mHeight, image.height, 2);
    
    memcpy(&newTexture->mBpp, &image.pixelSize, 1);
    
    if(newTexture->mBpp == 32)
        glTexImage2D(GL_TEXTURE_2D ,
                     0,
                     GL_RGBA,
                     newTexture->mWidth,
                     newTexture->mHeight,
                     0,
                     GL_BGRA,
                     GL_UNSIGNED_BYTE,
                     image.data);
    else if(newTexture->mBpp == 24)
        glTexImage2D( GL_TEXTURE_2D ,
                     0,
                     GL_RGB,
                     newTexture->mWidth,
                     newTexture->mHeight,
                     0,
                     GL_BGR,
                     GL_UNSIGNED_BYTE,
                     image.data);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    return newTexture;
}

NAMESPACE_END(GEngine);
