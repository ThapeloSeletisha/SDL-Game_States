#include "Game.hpp"

Game* Game::instance = nullptr;

Game::Game()
{
    window = nullptr;
    renderer = nullptr;
    running = true;
}

Game* Game::Instance()
{
    if (!instance) {
        instance = new Game();
    }
    return instance;
}

bool Game::I_init(char* title, int x, int y, int w, int h)
{
    // Initialize the SDL2 library
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        cout << "Failed to initialize SDL2" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return false;
    }

    // Initialize window
    Uint32 flags = SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow(title, 
        x, y,
        w, h, flags);
    
    if(!window)
    {
        cout << "Failed to create window" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return false;
    }

    // Initialize renderer
    renderer = SDL_CreateRenderer(window, -1, 
        SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        cout << "Failed to create renderer" << endl;
        cout << "SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return true;
}

bool Game::init(char* title, int x, int y, int w, int h)
{
    return Instance()->I_init(title ,x ,y ,w ,h);
}

void Game::I_render()
{
    SDL_RenderClear(renderer);
    // SDL_RenderCopy(texture)
    SDL_RenderPresent(renderer);
}

void Game::render()
{
    Instance()->I_render();
}

void Game::I_handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
        }
    }
}

void Game::handleEvents()
{
    Instance()->I_handleEvents();
}

void Game::I_update()
{
    // empty
}

void Game::update()
{
    Instance()->I_update();
}

void Game::I_clean()
{
    // empty
}

void Game::clean()
{
    Instance()->I_clean();
}

void Game::I_quit()
{
    // empty
}

void Game::quit()
{
    Instance()->I_quit();
}

SDL_Renderer* Game::I_getRenderer()
{
    return renderer;
}

SDL_Renderer* Game::getRenderer()
{
    return Instance()->I_getRenderer();
}

bool Game::I_isRunning()
{
    return running;
}

bool Game::isRunning()
{
    return Instance()->I_isRunning();
}