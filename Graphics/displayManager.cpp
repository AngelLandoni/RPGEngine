//
//  displayManager.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 11/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "displayManager.hpp"

NAMESPACE_BEGIN(GEngine);

DisplayManager::DisplayManager():
mIsClosed(false),
mFullscreenMode(false),
mWasCreated(false) {
    mBaseViewport.width = DISPLAYMANAGER_DEFAULT_SIZE_WIDTH;
    mBaseViewport.height = DISPLAYMANAGER_DEFAULT_SIZE_HEIGHT;
    mSize.height = DISPLAYMANAGER_DEFAULT_SIZE_HEIGHT;
    mSize.width = DISPLAYMANAGER_DEFAULT_SIZE_WIDTH;
}

DisplayManager::~DisplayManager() {
    SDL_GL_DeleteContext(mGLContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

DisplayManager& DisplayManager::getInstance() {
    static DisplayManager instance;
    return instance;
}

void DisplayManager::create() {
    // Initialize sdl2.
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        log(DISPLAYMANAGER_ERROR_ON_INIT_SDL, LogType::ERROR);
        return;
    }
    // Get the current window's configuration.
    //int windowMode = SDL_WINDOW_OPENGL | mFullscreenMode ? SDL_WINDOW_FULLSCREEN : 0;
    int windowMode = SDL_WINDOW_OPENGL;
    // Setup all the attributes.
    configureGLAttributes();
    // Alloc a new sdl window.
    mWindow = SDL_CreateWindow(mTitle.c_str(),
                               mPosition.x, mPosition.y,
                               mSize.width, mSize.height,
                               windowMode);
    // Create the context.
    mGLContext = SDL_GL_CreateContext(mWindow);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glViewport(0, 0, mBaseViewport.width, mBaseViewport.height);
    
    mWasCreated = true;
}

void DisplayManager::update() {
    if (!mWasCreated) return;
    SDL_GL_SwapWindow(mWindow);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a);
}

void DisplayManager::close() {
    mIsClosed = true;
}

// MARK: - Private methods.

void DisplayManager::configureGLAttributes() {
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, DISPLAYMANAGER_MAX_GL_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, DISPLAYMANAGER_MIN_GL_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}

NAMESPACE_END(GEngine);
