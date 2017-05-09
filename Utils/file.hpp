//
//  file.hpp
//  HitBox
//
//  Created by Angel Land on 25/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef file_hpp
#define file_hpp

#include <string>
#include <fstream>

#include "codeExtension.hpp"
#include "log.hpp"

NAMESPACE_BEGIN(GEngine);

#define FILE_ERROR_EMPTYNAMEFILE "The name can not be empty."
#define FILE_ERROR_NOFILE "The file doesn't exist."
#define FILE_ERROR_ONALLOCATIONMEMORY "Allocation error."

class File{
  // All the data.
  char* mBuffer;
  // Size of the data.
  unsigned int mBufferSize;
  // File name.
  std::string mFileName;
public:
  File();
  File(std::string _fileName);
  virtual ~File();
  // Load from file.
  bool load(std::string _fileName);
  // Return the buffer
  char* getData() const;
};

NAMESPACE_END(GEngine);

#endif /* file_hpp */
