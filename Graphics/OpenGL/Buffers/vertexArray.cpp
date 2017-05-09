//
//  vertexArray.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "vertexArray.hpp"

NAMESPACE_BEGIN(GEngine);

VertexArray::VertexArray() {
  glGenVertexArrays(1, &mID);
}

VertexArray::~VertexArray() {

}

void VertexArray::addBuffer(const Buffer _buffer, const Buffer::Type _type) {
  bind();
  _buffer.bind();
 
  glEnableVertexAttribArray(_type);
  glVertexAttribPointer(_type, _buffer.getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
  
  _buffer.unBind();
  unBind();
}

void VertexArray::bind() const {
  glBindVertexArray(mID);
}

void VertexArray::unBind() const {
  glBindVertexArray(0);
}


NAMESPACE_END(GEngine);
