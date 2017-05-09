//
//  path.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef path_hpp
#define path_hpp

#include <iostream>
#include <unistd.h>
#include <string>
#include <map>

#include "codeExtension.hpp"

#define GetCurrentDir getcwd
#define PATH_MAXFILENAME 255

NAMESPACE_BEGIN(GEngine);

class Path {
  std::string mBasePath;
  std::map<std::string,std::string> mPaths;
public:
  Path();
  virtual ~Path();
  void setBasePath(const std::string _dir);
  void add(const std::string _tag, const std::string _dir);
  void add(const std::map<std::string,std::string> _dirs);
  std::string operator[](const std::string _tag);
  void show() const;
};

std::string getCurrentBinaryPath();

NAMESPACE_END(GEngine);

#endif /* path_hpp */
