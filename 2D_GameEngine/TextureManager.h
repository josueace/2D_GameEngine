//
//  TextureManager.h
//  2D_GameEngine
//
//  Created by Josue Acevedo on 10/31/24.
//

#include "Game.hpp"


class TextureManager{
    
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};

