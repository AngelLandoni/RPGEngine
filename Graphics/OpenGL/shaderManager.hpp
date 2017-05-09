//
//  shaderManager.hpp
//  HitBox
//
//  Created by Angel Land on 25/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef shaderManager_hpp
#define shaderManager_hpp

#include <string>
#include <atomic>
#include <tuple>
#include <vector>

// OpenGL library
#include "../../../External/includes/Glew/glew.h"
#include "../../Utils/codeExtension.hpp"
#include "../../Utils/file.hpp"
#include "../../Components/basicCamera.hpp"

#include "shader.hpp"

NAMESPACE_BEGIN(GEngine);

// Errors
#define SHADERMANAGER_ERROR_LOADGINFILE "Error on load shader."
// Parse tokens
#define SHADERMANAGER_PARSETOKEN_OPENBRAKETS '['
#define SHADERMANAGER_PARSETOKEN_CLOSEBRAKETS ']'
#define SHADERMANAGER_PARSETOKEN_COLON ':'
// Keywords
#define SHADERAMANGER_KEYWORD_VERTEX "VERTEX"
#define SHADERAMANGER_KEYWORD_FRAGMENT "FRAGMENT"
//Tokens
#define SHADERMANAGER_TOKEN_ENDSTRING '\0'
// Messages
#define SHADERMANAGER_ERROR_COMPILING_SHADER "Error compiling shader."
#define SHADERMANAGER_ERROR_COMPILING_PROGRAM "Error compiling program."

#define ShaderManagerInstance ShaderManager::getInstance()

class ShaderManager {
    // Contain the number of shaders created
    // and compiled by the manager.
    //static unsigned int mNumberOfShaders;
    // Contain all the references of the shaders.
    std::vector<Shader*> mRefShaders;
    // Contain all the names of the shaders files.
    std::vector<std::string> mFileNameRefShaders;
public:
    // Return the instance of the Manager
    static ShaderManager& getInstance();
    // Compile a high level shader.
    Shader* compile(std::string _fileName);
    // Compile a high level shader from code.
    Shader* compileFromCode(std::string _code);
    // Delete a high level and low level shader using a shader.
    bool remove(Shader* _shader);
    // Delete a high level and low level shader the name of it.
    bool remove(std::string _fileName);
    // Show in a specific shader in console.
    void dump(Shader* _shader);
    // Show all the shaders in console.
    void dumpAll();
private:
    ShaderManager();
    virtual ~ShaderManager();
    // Return the shader if it is in the array of
    // shader reference.
    Shader* searchFile(std::string _fileName);
    // Parse and analice all the shader code.
    // Remember, all the shaders are in the same
    // string.
    std::tuple<std::string,std::string> preprocessShader(std::string _code);
    // Compile shader.
    // [1] Source.
    // [2] Type of shader.
    unsigned int compileShader(std::string _source, GLenum _type);
    // Create the shader program based on the shaders.
    unsigned int makeProgram(unsigned int _vertex,unsigned int _fragment);
    // Clear shaders from GPU, if these are removed
    // they can not by usend in the future, they will
    // need compile again.
    void clearShaders(unsigned int _vertex,unsigned int _fragment);
    // This method update the projection and view
    // of all the shaders.
    void updateProjectionAndView(const BasicCamera* camera);
private:
    friend class Scene;
};

// Static var initialization.
//unsigned int ShaderManager::mNumberOfShaders = 0;

NAMESPACE_END(GEngine);

#endif /* shaderManager_hpp */
