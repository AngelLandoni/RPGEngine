//
//  string.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 6/11/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "string.hpp"

NAMESPACE_BEGIN(GEngine);

std::vector<std::string> string_parse(const std::string _buffer, const char _token) {
  unsigned int i = 0;
  const unsigned int bufferLength = (unsigned int)_buffer.length();
  std::vector<std::string> data;
  std::string temp = "";
  while (i<bufferLength) {
    if (_buffer[i] == _token) {
      data.push_back(temp);
      temp = "";
      i++;
      continue;
    }
    temp += _buffer[i];
    i++;
  }
  data.push_back(temp);
  return data;
}



NAMESPACE_END(GEngine);
