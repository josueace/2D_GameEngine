//
//  TextureManager.cpp
//  2D_GameEngine
//
//  Created by Josue Acevedo on 10/31/2
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex= SDL_CreateTextureFromSurface(ren,tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return tex;
    
}
