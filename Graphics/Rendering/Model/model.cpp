//
//  model.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 1/14/17.
//  Copyright © 2017 AngelLandoni. All rights reserved.
//

#include "model.hpp"

NAMESPACE_BEGIN(GEngine);

Model::Model() {

}

Model::Model(const RawModel rawModel) {
    mVertexArray.addBuffer(rawModel.vertices, Buffer::Type::VERTEX);
    mVertexArray.addBuffer(rawModel.uvs, Buffer::Type::TEXTURE);
    mIndexBuffer = rawModel.index;
}

Model::~Model() {
    
}

void Model::setRawModel(const RawModel rawModel) {
    mVertexArray.addBuffer(rawModel.vertices, Buffer::Type::VERTEX);
    mVertexArray.addBuffer(rawModel.uvs, Buffer::Type::TEXTURE);
    mIndexBuffer = rawModel.index;
}



NAMESPACE_END(GEngine);