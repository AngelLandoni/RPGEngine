//
//  InputManager.hpp
//  RPGGameEngine
//
//  Created by Angel Land on 11/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#ifndef inputManager_hpp
#define inputManager_hpp

#include <atomic>
#include <map>
#include <functional>

#include <SDL2/SDL.h>

#include "../Utils/codeExtension.hpp"

#include "../Maths/point.hpp"

#include "../Graphics/displayManager.hpp"

NAMESPACE_BEGIN(GEngine);

#define INPUTMANAGER_MAX_KEYS 265

#define InputManagerIntance InputManager::getInstance()

enum KeyState { UP,DOWN };

class InputManager {
    Point<int> mMousePosition;
    SDL_Event mEvent;
    std::atomic<bool> mKeyState[INPUTMANAGER_MAX_KEYS];
    std::map<Uint32,std::function<void(KeyState)>> mKeyStateCallback;
    std::function<void(Uint32)> mKeyUp;
    std::function<void(Uint32)> mKeyDown;
public:
    static InputManager& getInstance();
    
    void setMousePosition(const Point<int> position);
    void hideMouse();
    void showMouse();
    
    inline Point<int> getMousePosition() const { return mMousePosition; }
    inline bool getKeyState(const Uint32 key) const { return mKeyState[key]; }
    inline void addHook(const Uint32 key,std::function<void(KeyState)> callback) {
        mKeyStateCallback[key] = callback;
    }
    inline void onKeyDown(std::function<void(Uint32)> callback) { mKeyDown = callback; }
    inline void onKeyUp(std::function<void(Uint32)> callback) { mKeyUp = callback; }
    
    void update();
private:
    InputManager();
    virtual ~InputManager();
};

NAMESPACE_END(GEngine);

#endif /* inputManager_hpp */
