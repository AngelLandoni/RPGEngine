//
//  modelManager.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 30/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "modelManager.hpp"

NAMESPACE_BEGIN(GEngine);

ModelLoader::ModelLoader() {}
ModelLoader::~ModelLoader() {}

ModelLoader& ModelLoader::getInstance() {
    static ModelLoader instance;
    return instance;
}

RawModel ModelLoader::loadOBJ(const std::string _file) {
    // Temp variables.
    RawModel model;
    std::string line;
    std::vector<float> vertices,textures,normals;
    std::vector<ushort> vertexIndices,texturesIndices,normalIndices;
    
    // Load from file and get all the data in the
    // buffers.
    std::ifstream file(_file.c_str());
    // If is not pissible load the file we return an error.
    if (!file.is_open()) {
        std::cout<<"Error on load file: "<<_file<<std::endl;
        std::cout.flush();
        return model;
    }
    // Get line by line.
    while (std::getline(file,line)) {
        // Avoid empty lines and needless lines.
        if (line.empty() || line[0] == '#' || line[0] == 'o' || line[0] == 's') continue;
        // Split the line in order to get the components.
        std::vector<std::string> lineValues = string_parse(line,MODELMANAGER_OBJ_TOKEN_SPACE);
        // Check if the line is a vertex line.
        if (lineValues[0] == MODELMANAGER_OBJ_TOKEN_VERTEX) {
            // Load x,y,z into the vertices.
            vertices.push_back(std::atof(lineValues[MODELMANAGER_OBJ_X_COMPONENT].c_str()));
            vertices.push_back(std::atof(lineValues[MODELMANAGER_OBJ_Y_COMPONENT].c_str()));
            vertices.push_back(std::atof(lineValues[MODELMANAGER_OBJ_Z_COMPONENT].c_str()));
            continue;
        }
        // Check if the line is a texture line.
        if (lineValues[0] == MODELMANAGER_OBJ_TOKEN_TEXTURE) {
            // Load x,y into the textures.
            textures.push_back(std::atof(lineValues[MODELMANAGER_OBJ_X_COMPONENT].c_str()));
            textures.push_back(std::atof(lineValues[MODELMANAGER_OBJ_Y_COMPONENT].c_str()));
            continue;
        }
        // Check if the line is a normal line.
        if (lineValues[0] == MODELMANAGER_OBJ_TOKEN_NORMAL) {
            // Load x,y,z into the normals.
            normals.push_back(std::atof(lineValues[MODELMANAGER_OBJ_X_COMPONENT].c_str()));
            normals.push_back(std::atof(lineValues[MODELMANAGER_OBJ_Y_COMPONENT].c_str()));
            normals.push_back(std::atof(lineValues[MODELMANAGER_OBJ_Z_COMPONENT].c_str()));
            continue;
        }
        // If the line is a face we need parse it by each
        // face.
        if (lineValues[0] == MODELMANAGER_OBJ_TOKEN_FACE) {
            // Get all the components.
            std::vector<std::string> pointA = string_parse(lineValues[1],MODELMANAGER_OBJ_TOKEN_SLASH);
            std::vector<std::string> pointB = string_parse(lineValues[2],MODELMANAGER_OBJ_TOKEN_SLASH);
            std::vector<std::string> pointC = string_parse(lineValues[3],MODELMANAGER_OBJ_TOKEN_SLASH);
            // Push all the vertex indices into the correct vector.
            vertexIndices.push_back(std::atoi(pointA[0].c_str()) - 1);
            vertexIndices.push_back(std::atoi(pointB[0].c_str()) - 1);
            vertexIndices.push_back(std::atoi(pointC[0].c_str()) - 1);
            // Push all the textures idices into the correct vector.
            texturesIndices.push_back(std::atoi(pointA[1].c_str()) - 1);
            texturesIndices.push_back(std::atoi(pointB[1].c_str()) - 1);
            texturesIndices.push_back(std::atoi(pointC[1].c_str()) - 1);
            // Push all the normal indices into the correct vector.
            normalIndices.push_back(std::atoi(pointA[2].c_str()) - 1);
            normalIndices.push_back(std::atoi(pointB[2].c_str()) - 1);
            normalIndices.push_back(std::atoi(pointC[2].c_str()) - 1);
            continue;
        }
    }
    
    // Correct texture index.
    // OpenGL use the same index for all the components
    // of the model. We need recalculate it in order to use
    // the same index for all the components.
    // We need iterate for each of the index and map
    // if the vertex with a texture coord exist if it exists
    // we should save the index if not we need create a new one
    // and save it.
    
    std::vector<float> outVertices,outTextures,outNormals;
    std::vector<ushort> outIndices;
    
    int i = 0, j = 0, l = 0, vertexIndexCorrection = 0, textureIndexCorrection = 0;
    bool foundCoincidence = false;
    const unsigned int lengthIndex = (const unsigned int)vertexIndices.size();
    
    while (i<lengthIndex) {
        // Search the 2 components.
        foundCoincidence = false;
        vertexIndexCorrection = vertexIndices[i] * 3;
        textureIndexCorrection = texturesIndices[i] * 2;
        j = 0;
        l = 0;
        while (j<outVertices.size()) {
            // If the vertex and texture are equal we
            // save the index into the list.
            if (
                // Vertex
                vertices[vertexIndexCorrection] == outVertices[j] &&
                vertices[vertexIndexCorrection + 1] == outVertices[j + 1] &&
                vertices[vertexIndexCorrection + 2] == outVertices[j + 2] &&
                // Texture
                textures[textureIndexCorrection] == outTextures[l] &&
                textures[textureIndexCorrection + 1] == outTextures[l + 1]
                ) {
                // Add the index where we found the coincidence.
                outIndices.push_back(j);
                foundCoincidence = true;
                // break;
            }
            l += 2;
            j += 3;
        }
        // If we did not found coincidences we should save the data.
        if (!foundCoincidence) {
            // Vertex
            outVertices.push_back(vertices[vertexIndexCorrection]);
            outVertices.push_back(vertices[vertexIndexCorrection + 1]);
            outVertices.push_back(vertices[vertexIndexCorrection + 2]);
            outIndices.push_back(outVertices.size() - 3); // -2 ?
            // Texture
            outTextures.push_back(textures[textureIndexCorrection]);
            outTextures.push_back(textures[textureIndexCorrection + 1]);
        }
        i++;
    }
    
    // Index correction (WTF?)
    for (ushort& item : outIndices) item /= 3;
    
    model.index.set(outIndices);
    model.vertices.set(outVertices, 3);
    model.uvs.set(outTextures, 2);
    model.normals.set(normals, 3);

    return model;
}

NAMESPACE_END(GEngine);
