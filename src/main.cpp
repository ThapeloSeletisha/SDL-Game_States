#include <iostream>
#include <SDL2/SDL.h>
using namespace std;


int main(int argc, char* args[])
{
    SDL_Window* m_Window = nullptr;
    cout << "before breakpoint" << endl;
    SDL_Renderer* m_Renderer = nullptr;
    bool m_running = true;  

    // Initialize the SDL2 library
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        cout << "Failed to initialize SDL2" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return -1;
    }

    Uint32 flags = SDL_WINDOW_SHOWN;
    m_Window = SDL_CreateWindow("Game", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, flags);
    
    if(!m_Window)
    {
        cout << "Failed to create window" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return -1;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, 
        SDL_RENDERER_ACCELERATED);

    if (!m_Renderer)
    {
        cout << "Failed to create renderer" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return -1;
    }
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);

    SDL_Delay(5000);
    cout << "it worked" << endl;

    return 0;
}