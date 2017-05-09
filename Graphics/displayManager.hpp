//
//  displayManager.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 11/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef displayManager_hpp
#define displayManager_hpp

#include <string>

#include "../../External/includes/Glew/glew.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "../Utils/codeExtension.hpp"
#include "../Utils/log.hpp"
#include "../Maths/rect.hpp"
#include "../Maths/point.hpp"
#include "../Maths/color.hpp"

NAMESPACE_BEGIN(GEngine);

#define DISPLAYMANAGER_ERROR_ON_INIT_SDL "Error on init SDL2."

#define DISPLAYMANAGER_DEFAULT_SIZE_WIDTH  500
#define DISPLAYMANAGER_DEFAULT_SIZE_HEIGHT 500

#define DISPLAYMANAGER_MIN_GL_VERSION 2
#define DISPLAYMANAGER_MAX_GL_VERSION 3

#define DisplayManagerInstance DisplayManager::getInstance()

class DisplayManager {
    SDL_Window* mWindow;
    SDL_GLContext mGLContext;
    std::string mTitle;
    Rect<int> mSize;
    Rect<float> mBaseViewport;
    Point<int> mPosition;
    Color mBackgroundColor;
    bool mFullscreenMode;
    bool mIsClosed;
    bool mWasCreated;
public:
    static DisplayManager& getInstance();
    
    inline void setTitle(const std::string title) { mTitle = title; }
    inline void setSize(const Rect<int> size) { mSize = size; }
    inline void setPosition(const Point<int> position) { mPosition = position; }
    inline void setViewport(const Rect<float> size) { mBaseViewport = size; }
    inline void setFullscreenMode(const bool state) { mFullscreenMode = state; }
    inline void setBackgroundColor(const Color background) { mBackgroundColor = background; }
    
    inline Rect<int> getSize() const { return mSize; }
    
    inline bool isClosed() const { return mIsClosed; }
    
    inline SDL_Window* getWindow() const { return mWindow; }
    
    void create();
    void update();
    void close();
private:
    DisplayManager();
    virtual ~DisplayManager();
    
    void configureGLAttributes();
};

NAMESPACE_END(GEngine);

#endif /* displayManager_hpp */
