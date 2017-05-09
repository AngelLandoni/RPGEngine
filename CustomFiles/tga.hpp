//
//  tga.hpp
//  HitBox
//
//  Created by Angel Land on 29/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef tga_hpp
#define tga_hpp

#include <iostream>
#include <string>
#include <fstream>

// Utils
#include "../Utils/codeExtension.hpp"

NAMESPACE_BEGIN(GEngine);

typedef struct TGA_FILE{
  char idLength; // Tamaño del campo id
  // Si es 0 no contiene mapa de colores
  // Si es 1 contiene mapa de colores
  // 2-127 para Truevision 128-255 para desarrolladores
  char colorMapType;
  // Si es 0 no se encuentra informacion
  // de la imagen
  // Si es 1 el mapeo de colores esta descomprimido
  char imageType; // Compresion y tipo de colores
  char colorMapSpecification[5]; // Descibre el mapa de colores
  char xOrigin[2]; // 2 bytes origen de la imagen en x
  char yOrigin[2]; // 2 bytes origne de la imagen en y
  char width[2];  // 2 bytes ancho en pixeles
  char height[2]; // 2 bytes alto en pixeles
  char pixelSize; // 1 byte Tamaño del pixel
  char imageDescriptor; // 1 byte WTF?
  
  unsigned int pixelDataSize;
  char* data;
}TGA_FILE;

TGA_FILE tga_load(const std::string _fileName);
void tga_dump(const TGA_FILE _file);

NAMESPACE_END(GEngine);

#endif /* tga_hpp */
