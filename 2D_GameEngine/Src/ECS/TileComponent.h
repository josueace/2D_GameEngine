#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    SDL_Rect tileRect;
    int tileID;
    char* path;
    
    TileComponent() = default;
    
    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;
        
        switch (tileID) {
            case 0:
                path="water.png";
                break;
            case 1:
                path="dirt.png";
                break;
            case 2:
                path="grass.png";
                break;
                
            default:
                break;
        }
    }
    void init() override
    {
        
    }
};
