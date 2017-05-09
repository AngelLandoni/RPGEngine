//
//  InputManager.cpp
//  RPGGameEngine
//
//  Created by Angel Land on 11/10/16.
//  Copyright © 2016 AngelLandoni. All rights reserved.
//

#include "inputManager.hpp"

NAMESPACE_BEGIN(GEngine);

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

InputManager& InputManager::getInstance() {
  static InputManager instance;
  return instance;
}

void InputManager::setMousePosition(const Point<int> position) {
    SDL_WarpMouseInWindow(DisplayManagerInstance.getWindow(),position.x,position.y);
}

void InputManager::hideMouse() {
    SDL_ShowCursor(SDL_DISABLE);
}

void InputManager::showMouse() {
    SDL_ShowCursor(SDL_ENABLE);
}

void InputManager::update() {
  // Check all the poll in order to
  // get all the events.
  while (SDL_PollEvent(&mEvent)) {
    // If the application receives a
    // quit action, it will close itself.
    if (mEvent.type == SDL_QUIT) {
      DisplayManagerInstance.close();
    }
    // Get the mouse position.
    SDL_GetMouseState(&mMousePosition.x, &mMousePosition.y);
    // Keyboard hooking.
    // If the key is down.
    if (mEvent.type == SDL_KEYDOWN) {
      // Calling generic callback.
      if (mKeyDown != nullptr && !mKeyState[mEvent.key.keysym.sym])
        mKeyDown(mEvent.key.keysym.sym);
      // Change the state of the key.
      mKeyState[mEvent.key.keysym.sym] = true;
      // Check if the key is setted.
      if (mKeyStateCallback.count(mEvent.key.keysym.sym) >= 1)
        mKeyStateCallback[mEvent.key.keysym.sym](KeyState::DOWN);
      continue;
    }
    // If the key is up
    if (mEvent.type == SDL_KEYUP) {
      // Calling generic callback.
      if (mKeyUp != nullptr && mKeyState[mEvent.key.keysym.sym])
        mKeyUp(mEvent.key.keysym.sym);
      // If the user release the key
      // it will change the state of the key.
      mKeyState[mEvent.key.keysym.sym] = false;
      if (mKeyStateCallback.count(mEvent.key.keysym.sym) >= 1)
        mKeyStateCallback[mEvent.key.keysym.sym](KeyState::UP);
    }
  }
}

NAMESPACE_END(GEngine);
