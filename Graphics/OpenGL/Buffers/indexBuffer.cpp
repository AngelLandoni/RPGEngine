//
//  indexBuffer.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "indexBuffer.hpp"

NAMESPACE_BEGIN(GEngine);

IndexBuffer::IndexBuffer() { }

IndexBuffer::IndexBuffer(const std::vector<ushort> _data):
mCount((uint)_data.size()) {
  allocData(_data);
}

IndexBuffer::~IndexBuffer() {}

void IndexBuffer::set(const std::vector<ushort> _data) {
  mCount = (uint)_data.size();
  allocData(_data);
}

void IndexBuffer::bind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
}

void IndexBuffer::unBind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

NAMESPACE_END(GEngine);
