//
//  tga.cpp
//  HitBox
//
//  Created by Angel Land on 29/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "tga.hpp"

NAMESPACE_BEGIN(GEngine);

TGA_FILE tga_load(const std::string _fileName){
  std::ifstream file(_fileName.c_str(),std::ifstream::binary);
  
  // TGA file header.
  TGA_FILE tgaFile;
  
  // Load head information.
  file.read((char*)&tgaFile,sizeof(TGA_FILE)-sizeof(unsigned int)-sizeof(char*)-2);

  // Calculate the size of the all pixels
  short width,height,bpp;
  memcpy(&width, &tgaFile.width[0], 2);
  memcpy(&height, &tgaFile.height[0], 2);
  memcpy(&bpp, &tgaFile.pixelSize, 1);
  
  tgaFile.pixelDataSize = width*height*(bpp/8);
  // Allocate memory for the pixel buffer.
  tgaFile.data = (char*)malloc(tgaFile.pixelDataSize);
  // Load the pixel buffer into memory.
  file.read((char*)tgaFile.data,tgaFile.pixelDataSize);
  
  // Flip bgr to rgb data
  unsigned int i = 0;
  char tempColor = 0;
  for(i=0;i<tgaFile.pixelDataSize;i+=bpp/8){
    // Save B color
    tempColor = tgaFile.data[i];
    tgaFile.data[i] = tgaFile.data[i+2];
    tgaFile.data[i+2] = tempColor;
  }
  
  return tgaFile;
}

void tga_dump(const TGA_FILE _file){
  unsigned int i=0;
  short bpp;
  memcpy(&bpp, &_file.pixelSize, 1);
  
  if(bpp == 32){
    for(i=0;i<_file.pixelDataSize;i+=bpp/4){
      std::cout<<"["<<(int)_file.data[i]<<","<<(int)_file.data[i+1]<<","<<(int)_file.data[i+2]<<","<<(int)_file.data[i+3]<<"]";
      std::cout.flush();
    }
    return;
  }
  
  for(i=0;i<_file.pixelDataSize;i+=bpp/4){
    std::cout<<"["<<(int)_file.data[i]<<","<<(int)_file.data[i+1]<<","<<(int)_file.data[i+2]<<"]";
    std::cout.flush();
  }
}

NAMESPACE_END(GEngine);
