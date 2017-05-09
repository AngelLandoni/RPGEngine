//
//  indexBuffer.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef indexBuffer_hpp
#define indexBuffer_hpp

#include <vector>

#include "../../../../External/includes/Glew/glew.h"

#include "../../../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

class IndexBuffer {
protected:
  uint mID;
  uint mCount;
public:
  IndexBuffer();
  IndexBuffer(const std::vector<ushort> data);
  virtual ~IndexBuffer();
  
  void set(const std::vector<ushort> data);
  
  inline uint getCount() const { return mCount; }
  
  void bind() const;
  void unBind() const;
private:
  inline void allocData(std::vector<ushort> _data) {
    glGenBuffers(1, &mID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ushort) * _data.size(), _data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mID);
  }
};

NAMESPACE_END(GEngine);

#endif /* indexBuffer_hpp */
