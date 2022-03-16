#pragma once
#include <iostream>
using namespace std;

enum StateID
{
    PLAY, MENU, GAMEOVER, PAUSE
};

class GameState
{
public:
    GameState(){};
    virtual ~GameState(){};

    virtual void update(){};
    virtual void render(){};

    virtual bool onEnter(){};
    virtual bool onExit(){};

    virtual StateID getStateID(){};
};