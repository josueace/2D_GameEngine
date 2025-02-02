//
//  ECS.cpp
//  2D_GameEngine
//
//  Created by Josue Acevedo on 1/28/25.
//

#include <stdio.h>
#include "ECS.h"

void Entity::addGroup(Group mGroup)
{
    groupBitset[mGroup] = true;
    manager.AddToGroup(this, mGroup);
}
