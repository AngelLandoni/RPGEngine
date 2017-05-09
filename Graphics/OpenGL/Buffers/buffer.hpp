//
//  buffer.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef buffer_hpp
#define buffer_hpp

#include <vector>

#include "../../../../External/includes/Glew/glew.h"

#include "../../../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

class Buffer {
protected:
  uint mID, mComponetCount;
public:
  Buffer();
  Buffer(const std::vector<float> data, const uint componentCount);
  virtual ~Buffer();

  void set(const std::vector<float> data, const uint componentCount);
  
  void bind() const;
  void unBind() const;

  inline uint getComponentCount() const {  return mComponetCount; }
private:
  inline void allocData(const std::vector<float> data) {
    glGenBuffers(1, &mID);
    glBindBuffer(GL_ARRAY_BUFFER, mID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }
public:
  enum Type {
    VERTEX,
    TEXTURE,
    NORMAL
  };
};

NAMESPACE_END(GEngine);

#endif /* buffer_hpp */
