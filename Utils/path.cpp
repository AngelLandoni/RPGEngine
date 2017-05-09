//
//  path.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "path.hpp"

NAMESPACE_BEGIN(GEngine);

Path::Path():
mBasePath("")
{}

Path::~Path() {

}

void Path::setBasePath(const std::string _dir) {
  mBasePath = _dir;
}

void Path::add(const std::string _tag, const std::string _dir) {
  mPaths[_tag] = _dir;
}

void Path::add(const std::map<std::string,std::string> _dirs) {
  mPaths.insert(_dirs.begin(), _dirs.end());
}

std::string Path::operator[](const std::string _tag) {
  return mBasePath + mPaths[_tag];
}

void Path::show() const {
  for (auto &item : mPaths) {
    std::cout<<item.first<<" -> "<<item.second<<std::endl;
    std::cout.flush();
  }
}

std::string getCurrentBinaryPath() {
  char cCurrentPath[PATH_MAXFILENAME];
  GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));
  return std::string(cCurrentPath);
}

NAMESPACE_END(GEngine);
