//
//  file.cpp
//  HitBox
//
//  Created by Angel Land on 25/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "file.hpp"

NAMESPACE_BEGIN(GEngine);

File::File(){
  mBuffer = nullptr;
}

File::File(std::string _fileName){
  load(_fileName);
}

File::~File(){

}

bool File::load(std::string _fileName){
  if(_fileName == ""){
    log(FILE_ERROR_EMPTYNAMEFILE, LogType::WARNING);
    return false;
  }
  
  FILE* cFile;
  cFile = fopen(_fileName.c_str(), "rb");
  
  if(!cFile){
    log(FILE_ERROR_NOFILE, LogType::WARNING);
    return false;
  }
  
  fseek(cFile, 0, SEEK_END);
  mBufferSize = (unsigned int)ftell(cFile);
  fseek(cFile, 0, SEEK_SET);
  
  mBuffer = (char*)malloc(mBufferSize+1);
  if (!mBuffer){
    log(FILE_ERROR_ONALLOCATIONMEMORY, LogType::WARNING);
    fclose(cFile);
    return false;
  }
  
  fread(mBuffer, mBufferSize, 1,cFile);
  fclose(cFile);
  
  mBuffer[mBufferSize] = '\0';
  
  return true;
}

char* File::getData() const{
  return mBuffer;
}

NAMESPACE_END(GEngine);
