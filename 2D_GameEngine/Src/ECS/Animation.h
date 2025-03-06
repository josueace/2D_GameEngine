//
//  Animation.h
//  2D_GameEngine
//
//  Created by Josue Acevedo on 3/6/25.
//
#pragma once

struct Animation
{
    int index;
    int frames;
    int speed;
    
    Animation() {}
    Animation(int i, int f, int s)
    {
        index = i;
        frames = f;
        speed = s;
    }
};
