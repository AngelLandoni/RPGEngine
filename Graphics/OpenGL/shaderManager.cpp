//
//  shaderManager.cpp
//  HitBox
//
//  Created by Angel Land on 25/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "shaderManager.hpp"

NAMESPACE_BEGIN(GEngine);

//MARK: Public Methods

ShaderManager& ShaderManager::getInstance(){
    static ShaderManager instance;
    return instance;
}

Shader* ShaderManager::compile(std::string _fileName){
    Shader* refShader = searchFile(_fileName);
    if(refShader != nullptr)
        return refShader;
    
    File shaderFile;
    if(!shaderFile.load(_fileName)){
        log(SHADERMANAGER_ERROR_LOADGINFILE, LogType::WARNING);
        return nullptr;
    }
    
    char* buffer = shaderFile.getData();
    std::string glslVertexSource = "",glslFragmentSource = "";
    std::tie(glslVertexSource,glslFragmentSource) = preprocessShader(std::string((char*)buffer)+SHADERMANAGER_TOKEN_ENDSTRING);
    delete[] buffer;
    
    unsigned int vertexLocation = compileShader(glslVertexSource+'\0',GL_VERTEX_SHADER);
    unsigned int fragmentLocation = compileShader(glslFragmentSource+'\0',GL_FRAGMENT_SHADER);
    
    unsigned int finalProgram = makeProgram(vertexLocation, fragmentLocation);
    
    Shader* newShader = new Shader();
    mRefShaders.push_back(newShader);
    mFileNameRefShaders.push_back(_fileName);
    newShader->mProgram = finalProgram;
    
    clearShaders(vertexLocation, fragmentLocation);
    
    return newShader;
}

Shader* ShaderManager::compileFromCode(std::string _code){
    std::string glslVertexSource = "",glslFragmentSource = "";
    std::tie(glslVertexSource,glslFragmentSource) = preprocessShader(_code);
    
    unsigned int vertexLocation = compileShader(glslVertexSource+SHADERMANAGER_TOKEN_ENDSTRING,GL_VERTEX_SHADER);
    unsigned int fragmentLocation = compileShader(glslFragmentSource+SHADERMANAGER_TOKEN_ENDSTRING,GL_FRAGMENT_SHADER);
    
    unsigned int finalProgram = makeProgram(vertexLocation, fragmentLocation);
    
    Shader* newShader = new Shader();
    mRefShaders.push_back(newShader);
    mFileNameRefShaders.push_back("");
    newShader->mProgram = finalProgram;
    
    clearShaders(vertexLocation, fragmentLocation);
    
    return newShader;
}

bool ShaderManager::remove(Shader* _shader){
    unsigned int i = 0;
    const unsigned int lengthShaders = (const unsigned int)mRefShaders.size();
    for(i=lengthShaders;i>0;i--) if(mRefShaders[i] == _shader){
        glDeleteProgram(_shader->mProgram);
        delete _shader;
        mRefShaders[i] = nullptr;
        mFileNameRefShaders[i] = "";
        return true;
    }
    return false;
}

bool ShaderManager::remove(std::string _fileName){
    unsigned int i = 0;
    const unsigned int lengthShaders = (const unsigned int)mFileNameRefShaders.size();
    for(i=lengthShaders;i>0;i--) if(mFileNameRefShaders[i] == _fileName){
        glDeleteProgram(mRefShaders[i]->mProgram);
        delete mRefShaders[i];
        mRefShaders[i] = nullptr;
        mFileNameRefShaders[i] = "";
        return true;
    }
    return false;
}

void ShaderManager::dump(Shader *_shader){
    unsigned int i = 0;
    const unsigned int lengthShaders = (const unsigned int)mRefShaders.size();
    
    std::cout<<"[SHADERS]:"<<std::endl;
    std::cout.flush();
    for(i=0;i<lengthShaders;i++) if(mRefShaders[i] == _shader){
        std::cout<<"["<<mFileNameRefShaders[i]<<" | "<<mRefShaders[i]->mProgram<<"]"<<std::endl;
        std::cout.flush();
        return;
    }
}

void ShaderManager::dumpAll(){
    unsigned int i = 0;
    const unsigned int lengthShaders = (const unsigned int)mRefShaders.size();
    
    std::cout<<"[SHADERS]:"<<std::endl;
    std::cout.flush();
    for(i=0;i<lengthShaders;i++){
        std::cout<<"["<<mFileNameRefShaders[i]<<" | "<<mRefShaders[i]->mProgram<<"]"<<std::endl;
        std::cout.flush();
    }
}

//MARK: Private Methods

ShaderManager::ShaderManager(){}

ShaderManager::~ShaderManager(){
    for(Shader* item : mRefShaders){
        glDeleteProgram(item->mProgram);
        delete item;
    }
}

Shader* ShaderManager::searchFile(std::string _fileName){
    unsigned int i = 0;
    const unsigned int lengthFileNameVector = (unsigned int)mFileNameRefShaders.size();
    for(i=0;i<lengthFileNameVector;i++) if(mFileNameRefShaders[i] == _fileName)
        return mRefShaders[i];
    return nullptr;
}

std::tuple<std::string,std::string> ShaderManager::preprocessShader(std::string _code){
    const unsigned int codeLength = (unsigned int)_code.size();
    unsigned int i = 0;
    
    std::string typeOfShader = "";
    std::string glslVertexCode = "";
    std::string glslFragmentCode = "";
    
    while (i<codeLength) {
        if(_code[i] != SHADERMANAGER_PARSETOKEN_OPENBRAKETS){
            i++;
            continue;
        }
        i++;
        
        typeOfShader = "";
        while(_code[i] != SHADERMANAGER_PARSETOKEN_CLOSEBRAKETS &&
              _code[i+1] != SHADERMANAGER_PARSETOKEN_COLON ){
            typeOfShader += _code[i];
            i++;
        }
        i += 2;
        
        if(typeOfShader == SHADERAMANGER_KEYWORD_VERTEX){
            while((_code[i] != SHADERMANAGER_PARSETOKEN_OPENBRAKETS) &&
                  (i <= codeLength) &&
                  (_code[i] != SHADERMANAGER_TOKEN_ENDSTRING) ){
                glslVertexCode += _code[i];
                i++;
            }
            continue;
        }
        
        if(typeOfShader == SHADERAMANGER_KEYWORD_FRAGMENT){
            while((_code[i] != SHADERMANAGER_PARSETOKEN_OPENBRAKETS) &&
                  (i <= codeLength) &&
                  (_code[i] != SHADERMANAGER_TOKEN_ENDSTRING) ){
                glslFragmentCode += _code[i];
                i++;
            }
            continue;
        }
        i++;
    }
    
    return std::make_tuple(glslVertexCode+'\0',glslFragmentCode+'\0');
}

unsigned int ShaderManager::compileShader(std::string _source,GLenum _type){
    const char* ptrSource = _source.c_str();
    const int* ptrSize = new int((int)_source.size());
    
    unsigned int shader = glCreateShader(_type);
    glShaderSource(shader, 1, &ptrSource, ptrSize);
    glCompileShader(shader);
    
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        char log_[512];
        glGetShaderInfoLog(shader, 512, NULL, log_);
        log(SHADERMANAGER_ERROR_COMPILING_SHADER+std::string(log_), LogType::WARNING);
    }
    
    return shader;
}

unsigned int ShaderManager::makeProgram(unsigned int _vertex,unsigned int _fragment){
    unsigned int program = glCreateProgram();
    glAttachShader(program,_vertex);
    glAttachShader(program,_fragment);
    glLinkProgram(program);
    
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char log_[512];
        glGetProgramInfoLog(program, 512, NULL, log_);
        log(SHADERMANAGER_ERROR_COMPILING_PROGRAM+std::string(log_), LogType::WARNING);
    }
    
    return program;
}

void ShaderManager::clearShaders(unsigned int _vertex,unsigned int _fragment){
    glDeleteShader(_vertex);
    glDeleteShader(_fragment);
}

void ShaderManager::updateProjectionAndView(const BasicCamera* camera) {
    for (Shader* shader : mRefShaders) {
        shader->submit("projection", camera->getProjection());
        shader->submit("view", camera->getView());
    }
}

NAMESPACE_END(GEngine);




