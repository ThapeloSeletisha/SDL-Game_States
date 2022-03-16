#include "PlayState.hpp"
#include "MenuState.hpp"

const StateID PlayState::s_ID = PLAY;

PlayState::~PlayState()
{}

void PlayState::update()
{
    cout << "PlayState" << endl;
    if (InputHandler::getMouseButtonState(RIGHT))
    {
        GameStateMachine::changeState(new MenuState());
    }
}

void PlayState::render()
{
    // empty
}

bool PlayState::onEnter()
{
    return true;
}

bool PlayState::onExit()
{
    return true;
}

StateID PlayState::getStateID() const
{
    return s_ID;
}