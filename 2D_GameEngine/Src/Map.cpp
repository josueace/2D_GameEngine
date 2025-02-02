//
//  Map.cpp
//  2D_GameEngine
//
//  Created by Josue Acevedo on 11/8/24.
//

#include "Map.h"
#include "Game.hpp"
#include <fstream>



Map::Map()
{
    
}

Map::~Map()
{
    
}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
    char tile;
    std::fstream mapFile;
    mapFile.open(path);
    std::cout <<path;
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            mapFile.get(tile);
            Game::AddTile(atoi(&tile),32 * x, 32 * y);
            mapFile.ignore();
            std::cout << tile;
        }
        std::cout << std::endl;
    }

    mapFile.close();
}


