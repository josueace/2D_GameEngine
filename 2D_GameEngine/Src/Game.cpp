#include "Game.hpp"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"


Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
SDL_Event Game::event;
auto& player(manager.addEntity());

Game::Game()
{}
Game::~Game()
{}


void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags=0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        std::cout << "Subsystems Initialized!..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "window created!" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" <<std::endl;
        }
        isRunning =true;
       
    } else {
        isRunning = false;
    }
    
    map = new Map();
    
    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>("player.png");
    player.addComponent<KeyboardController>();
   
}

void Game::handleEvents()
{
   
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    manager.refresh();
    manager.update();
    
}
void Game::render()
{
    SDL_RenderClear(renderer);
    // this is where we add stuff to render
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}


