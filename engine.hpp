//
//  engine.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 10/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef engine_h
#define engine_h

#include "Utils/codeExtension.hpp"
#include "Utils/log.hpp"
#include "Utils/configFile.hpp"
#include "Utils/path.hpp"
#include "Utils/lua.hpp"

#include "Graphics/Rendering/renderer.hpp"
#include "Graphics/displayManager.hpp"
#include "Graphics/OpenGL/shaderManager.hpp"
#include "Graphics/OpenGL/Buffers/buffer.hpp"
#include "Graphics/OpenGL/Buffers/indexBuffer.hpp"
#include "Graphics/OpenGL/Buffers/vertexArray.hpp"
#include "Graphics/Texture/textureManager.hpp"
#include "Graphics/Texture/textureManager.hpp"
#include "Graphics/material.hpp"
#include "Graphics/materialManager.hpp"

#include "Graphics/Rendering/Model/modelManager.hpp"
#include "Graphics/Rendering/Model/model.hpp"

#include "Managers/inputManager.hpp"

#include "Components/basicCamera.hpp"
#include "Components/flyCamera.hpp"
#include "Components/scene.hpp"

NAMESPACE_BEGIN(GEngine);

#define GENGINE_VERSION "V0.1"

NAMESPACE_END(GEngine);

#endif /* engine_h */
