//
//  Game.hpp
//  2D_GameEngine
//
//  Created by Josue Acevedo on 10/3/24.
//

#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {
    
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() {return isRunning;}
    
    static void AddTile(int id,int x,int y);
    
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    
};

#endif /* Game_hpp */
