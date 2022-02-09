#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

int main(int argc, char* args[])
{
    cout << "start" << endl;
    
    if (!Game::Instance()->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480)) 
    {
        cout << "Failed to initialize game" << endl;
        return -1;
    }

    int count = 0;
    while (Game::Instance()->isRunning())
    {
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();
        count++;
        if (count > 5000)
        {
            cout << count << endl;
            break;
        }
    }

    return 0;
}