#include "MenuState.hpp"
#include "InputHandler.hpp"

const StateID MenuState::s_ID = MENU;

void MenuState::menuToPlay()
{
    GameStateMachine::changeState(new PlayState());
}

void MenuState::exitFromMenu()
{
    GameStateMachine::popState();
    Game::quit();
}

void MenuState::update()
{
    cout << "Menu State" << endl;
    if (InputHandler::getMouseButtonState(LEFT))
    {
        GameStateMachine::changeState(new PlayState());
    }
}

void MenuState::render()
{
    // empty
}

bool MenuState::onEnter()
{
    return true;
}

bool MenuState::onExit()
{
    return true;
}

StateID MenuState::getStateID() const
{
    return s_ID;
}