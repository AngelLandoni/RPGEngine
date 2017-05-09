//
//  texture.cpp
//  HitBox
//
//  Created by Angel Land on 4/6/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "texture.hpp"

NAMESPACE_BEGIN(GEngine);

Texture::Texture(){

}

Texture::~Texture(){
  glDeleteTextures(1, &mId);
}

void Texture::enable() const{
  glActiveTexture(mId);
  glBindTexture(GL_TEXTURE_2D,mId);
}

void Texture::disable() const{
  glBindTexture(GL_TEXTURE_2D,0);
}

NAMESPACE_END(GEngine);
