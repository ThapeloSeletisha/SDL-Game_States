#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Game.hpp"
using namespace std;

// Consider adding onKeyDown() and onKeyUp() functions

enum mouse_button
{
    LEFT, MIDDLE, RIGHT
};

class InputHandler
{
private:

    static InputHandler* instance;
    vector<bool> mouseButtonStates;

    void onMouseMove();
    void onMouseButtonDown(SDL_Event& e);
    void onMouseButtonUp(SDL_Event& e);

    InputHandler();
    static InputHandler* Instance();

    // Implementation of static functions
    void I_update();
    void I_clean();

    bool I_getMouseButtonState(mouse_button button);
    bool I_isKeyDown(SDL_Scancode key);

public:

    static void update();
    static void clean();

    static bool getMouseButtonState(mouse_button button);
    static bool isKeyDown(SDL_Scancode key);

};

