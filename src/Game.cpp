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

bool Game::init(char* title, int x, int y, int w, int h)
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

void Game::render()
{
    SDL_RenderClear(renderer);
    // SDL_RenderCopy(texture)
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    // empty
}

void Game::update()
{
    // empty
}

void Game::clean()
{
    // empty
}

void Game::quit()
{
    // empty
}

SDL_Renderer* Game::getRenderer()
{
    return renderer;
}

bool Game::isRunning()
{
    return running;
}