#include "InputHandler.hpp"

InputHandler* InputHandler::instance = nullptr;

InputHandler::InputHandler()
{
    mouseButtonStates = vector<bool>(3);
}

InputHandler* InputHandler::Instance()
{
    if (!instance) {
        instance = new InputHandler();
    }
    return instance;
}

/*Updates the mouse position
*/
void InputHandler::onMouseMove()
{
    // empty
}

/*Updates mouseButtonStates for mouse down event
*/
void InputHandler::onMouseButtonDown(SDL_Event& e)
{
    if (e.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = true;
    }
    if (e.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = true;
    }
    if (e.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = true;
    }
}

/*Updates mouseButtonStates for mouse up event
*/
void InputHandler::onMouseButtonUp(SDL_Event& e)
{
    if (e.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = false;
    }
    if (e.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = false;
    }
    if (e.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::I_update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Game::quit();
                break;

            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
        }
    }
}

/*Updates member variables when there is a new event
*/
void InputHandler::update()
{
    Instance()->I_update();
}

void InputHandler::I_clean()
{
    delete instance;
    instance = nullptr;
}

/*
*/
void InputHandler::clean()
{
    Instance()->I_clean();
}

bool InputHandler::I_getMouseButtonState(mouse_button button)
{
    return mouseButtonStates[button];
}

/*Checks if mouse button is down or up

Args: 
    button: enum for which mouse button to check

Returns:
    true if button is down and false otherwise
*/
bool InputHandler::getMouseButtonState(mouse_button button)
{
    return Instance()->getMouseButtonState(button);
}

bool InputHandler::I_isKeyDown(SDL_Scancode key)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    bool isDown = false;
    if (keyboardState)
    {
        if (keyboardState[key] == 1)
        {
            isDown = true;
        }
    }

    return isDown;
}

/*Checks if the given key is down

Args:
    key: the key that is to be checked

Returns:
    True if key is down and false otherwise
*/
bool InputHandler::isKeyDown(SDL_Scancode key)
{
    return Instance()->I_isKeyDown(key);
    /*Consider adding onKeyDown() and onKeyUp() functions
    */
}