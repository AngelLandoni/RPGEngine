//
//  shader.cpp
//  HitBox
//
//  Created by Angel Land on 25/5/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "shader.hpp"

NAMESPACE_BEGIN(GEngine);

Shader::Shader(){

}

Shader::~Shader(){
  
}

void Shader::enable() const{
  glUseProgram(mProgram);
}

void Shader::disable() const{
  glUseProgram(0);
}

void Shader::submit( const std::string _varName, const glm::vec2 _vector) const{
  enable();
  
  int loc = glGetUniformLocation(mProgram,_varName.c_str(  ));
  if(loc==-1) return;
  
  glUniform2f( loc,_vector.x,_vector.y );
  
  disable();
}

void Shader::submit(const std::string _varName, const float _value) const{
  enable();
  
  int loc = glGetUniformLocation(mProgram,_varName.c_str(  ));
  if(loc==-1) return;
  
  glUniform1f(loc,_value);
  
  disable();
}

void Shader::submit(const std::string _varName, const glm::vec3 _vector) const{
  enable();
  
  int loc = glGetUniformLocation(mProgram,_varName.c_str(  ));
  if(loc==-1) return;
  
  glUniform3f(loc,_vector.x,_vector.y,_vector.z);
  
  disable();
}

void Shader::submit( const std::string _varName, const glm::vec4 _vector ) const{
  enable();
  
  int loc = glGetUniformLocation(mProgram,_varName.c_str(  ));
  if(loc==-1) return;
  
  glUniform4f(loc,_vector.x,_vector.y,_vector.z,_vector.w);
  
  disable();
}

void Shader::submit( const std::string _varName, const glm::mat4 _matrix ) const {
  enable();
  
  int matrixID = glGetUniformLocation( mProgram, _varName.c_str(  ) );
  if( matrixID == -1 )
    return;
  
  glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr( _matrix ) );

  disable();
}

NAMESPACE_END(GEngine);
