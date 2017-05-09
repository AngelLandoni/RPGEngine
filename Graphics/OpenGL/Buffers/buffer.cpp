//
//  buffer.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "buffer.hpp"

NAMESPACE_BEGIN(GEngine);

Buffer::Buffer() {}

Buffer::Buffer(const std::vector<float> _data, const uint _componentCount):
mComponetCount(_componentCount) {
  allocData(_data);
}

Buffer::~Buffer() {
  
}

void Buffer::set(const std::vector<float> _data, const uint _componentCount) {
  mComponetCount = _componentCount;
  allocData(_data);
}

void Buffer::bind() const {
  glBindBuffer(GL_ARRAY_BUFFER, mID);
}

void Buffer::unBind() const {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}



NAMESPACE_END(GEngine);
