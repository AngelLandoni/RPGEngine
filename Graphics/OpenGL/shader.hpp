//
//  shader.hpp
//  HitBox
//
//  Created by Angel Land on 25/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <string>

#include "../../../External/includes/Glew/glew.h"

#include "../../Utils/codeExtension.hpp"

#include "../../../External/includes/glm/vec3.hpp"
#include "../../../External/includes/glm/mat4x4.hpp"
#include "../../../External/includes/glm/gtc/type_ptr.hpp"

NAMESPACE_BEGIN(GEngine);

// Contain the number of shaders to supported.
// [+] Vertex shader.
// [+] Fragment shader.
#define SHADER_MAX_SHADERS 2

// Shader represetnation on RAM.
// Contain a ref to the shader in GPU.
class Shader{
protected:
  // Reference to the program in GPU.
  unsigned int mProgram;
  // Contain all the supported shaders.
  //unsigned int mShaders[SHADER_MAX_SHADERS];
public:
  Shader();
  virtual ~Shader();
  // Active the shader.
  void enable() const;
  // Disable the shader.
  void disable() const;
  // Submit a uniform value to the GPU.
  void submit( const std::string _varName, const glm::vec2 _vector) const;
  void submit( const std::string _varName, const glm::vec3 _vector) const;
  void submit( const std::string _varName, const glm::vec4 _vector ) const;
  void submit( const std::string _varName, const float _value) const;
  void submit( const std::string _varName, const glm::mat4 _matrix ) const;

private:
  // Allow access to the ShaderManager.
  friend class ShaderManager;
};

static const std::string GLSLTransformationVar = "transform";

NAMESPACE_END(GEngine);

#endif /* shader_hpp */
