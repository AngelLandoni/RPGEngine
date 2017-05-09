//
//  configFile.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef configFile_hpp
#define configFile_hpp

#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <future>
#include <fstream>

#include "codeExtension.hpp"
#include "log.hpp"

NAMESPACE_BEGIN(GEngine);

#define CONFIGFILE_DEFAULT_TAG "GENERAL"
#define CONFIGFILE_START_TOKEN '['
#define CONFIGFILE_END_TOKEN ']'
#define CONFIGFILE_SEPARATOR_TOKEN ':'

#define CONFIGFILE_ERROR_ON_LOAD_FILE "Error on load file "

class ConfigFile {
  std::string mBasePath;
  std::map<std::string,std::map<std::string,std::string>> mProperties;
public:
  ConfigFile();
  virtual ~ConfigFile();
  void setBasePath(const std::string _basePath);
  bool load(const std::string _file);
  std::map<std::string,std::string> getByTag(const std::string _tag);
  std::map<std::string,std::string> operator[](const std::string _tag);
  void show() const;
};

NAMESPACE_END(GEngine);

#endif /* configFile_hpp */


