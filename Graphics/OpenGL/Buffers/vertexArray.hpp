//
//  vertexArray.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 16/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef vertexArray_hpp
#define vertexArray_hpp

#include "../../../Utils/codeExtension.hpp"
#include "buffer.hpp"

NAMESPACE_BEGIN(GEngine);

class VertexArray {
protected:
  uint mID;
  std::vector<Buffer> mBuffers;
public:
  VertexArray();
  virtual ~VertexArray();

  void addBuffer(const Buffer buffer, const Buffer::Type type);

  void bind() const;
  void unBind() const;
};

NAMESPACE_END(GEngine);

#endif /* vertexArray_hpp */
