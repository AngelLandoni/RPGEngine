//
//  configFile.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "configFile.hpp"

NAMESPACE_BEGIN(GEngine);

ConfigFile::ConfigFile():
mBasePath("")
{}

ConfigFile::~ConfigFile() {
  
}
// This method sets the base path.
void ConfigFile::setBasePath(const std::string _basePath) {
  mBasePath = _basePath;
}
// This method loads the configuration file.
bool ConfigFile::load(const std::string _file) {
    // Start code loader.
    std::string line = "", tag = CONFIGFILE_DEFAULT_TAG;
    std::ifstream file(mBasePath + _file, std::ifstream::in);
    
    if (!file.is_open()){
      log(CONFIGFILE_ERROR_ON_LOAD_FILE + mBasePath + _file, LogType::WARNING);
      return false;
    }
    
    while (getline(file,line)) {
      // Check if the line is null or only has
      // the jump line character.
      if(line.length() <= 1) continue;
      // Save the length of the line.
      const unsigned int lineLenght = (unsigned int)line.length();
      // Check if the first character is
      // a '[' in order to parte the tag.
      if (line[0] == CONFIGFILE_START_TOKEN) {
        // Set the i in 1 in order to avoid the first character.
        tag = "";
        unsigned int i = 1;
        while (i<lineLenght - 1) {
          if (line[0] == CONFIGFILE_END_TOKEN) {
            break;
          }
          tag += line[i];
          i++;
        }
        // Avoid execute needless code.
        continue;
      }
      // If the line is not a tag, we will save
      // the data in the map with te corresponding
      // tag.
      
      // Search the parse token.
      unsigned int i = 0;
      while (i<lineLenght) {
        if (line[i] == CONFIGFILE_SEPARATOR_TOKEN)
          break;
        i++;
      }
      // Set the property into the map data.
      mProperties[tag][line.substr(0,i)] = line.substr(i + 1,lineLenght);
    }

  return true;
}
// This method returns the specific map
// depending the tap passed by parameter.
std::map<std::string,std::string> ConfigFile::getByTag(const std::string _tag) {
  return mProperties[_tag];
}
// This method does the same that the
// before method but using the [] operator.
std::map<std::string,std::string> ConfigFile::operator[](const std::string _tag) {
  return mProperties[_tag];
}
// This method shows all the content
// of the configuration file.
void ConfigFile::show() const{
  for (auto &tag : mProperties) {
    std::cout<<"["<<tag.first<<"]"<<std::endl;
    std::cout.flush();
    for (auto &setting : tag.second) {
      std::cout<<"\t"<<setting.first<<":"<<setting.second<<std::endl;
      std::cout.flush();
    }
  }
}

NAMESPACE_END(GEngine);
