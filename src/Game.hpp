#pragma once
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class Game
{
private:

    SDL_Window* window;
    SDL_Renderer* renderer;

    bool running;
    static Game* instance;
    
    Game();

public:

    static Game* Instance();
    bool init(char* title, int x, int y, int w, int h);

    void render();
    void handleEvents();
    void update();
    
    void clean();
    void quit();

    SDL_Renderer* getRenderer();
    bool isRunning();

};