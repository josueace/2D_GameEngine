#pragma once
#include "Game.hpp"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Collision.h"
#include "ECS/Components.h"
#include <iostream>




Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupClassmates,
    groupColliders
};




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
    
    Map::LoadMap("assets/p16x16.map",16,16);
    
    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("player_anims.png",true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);
    
    wall.addComponent<TransformComponent>(300.0f,300.0f,300,20,1);
    wall.addComponent<SpriteComponent>("dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);
   
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
    
    for (auto cc: colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
}

auto& tile(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& classmate(manager.getGroup(groupClassmates));

void Game::render()
{
    SDL_RenderClear(renderer);
    // this is where we add stuff to render
    
    for (auto& t : tile)
    {
        t->draw();
    }
    for (auto& p : players)
    {
        p->draw();
    }

    for (auto& c : classmate)
    {
        c->draw();
    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::AddTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x,y,32,32,id);
    tile.addGroup(groupMap);
}
