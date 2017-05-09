//
//  renderer.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 14/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "renderer.hpp"

NAMESPACE_BEGIN(GEngine);

Renderer::Renderer() {}
Renderer::~Renderer() {}

void Renderer::submit(const Renderable& _renderable) {
    mRenderQueue.push_back(&_renderable);
}

void Renderer::flush() {
    while (!mRenderQueue.empty()) {
        const Renderable* rendereable = mRenderQueue.front();
        mRenderQueue.pop_front();
        rendereable->bind();
        // Enable all the variables.
        rendereable->mMaterial->mProgram->enable();
        rendereable->mModel->mVertexArray.bind();
        rendereable->mModel->mIndexBuffer.bind();
        // Draw!
        glDrawElements(GL_TRIANGLES, rendereable->mModel->mIndexBuffer.getCount(), GL_UNSIGNED_SHORT, 0);
        // Disable all the variables.
        rendereable->mModel->mIndexBuffer.unBind();
        rendereable->mModel->mVertexArray.unBind();
        rendereable->unBind();
    }
}

NAMESPACE_END(GEngine);
