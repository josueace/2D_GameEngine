//
//  Map.cpp
//  2D_GameEngine
//
//  Created by Josue Acevedo on 11/8/24.
//

#include "Map.h"
#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;


Map::Map()
{
    
}

Map::~Map()
{
    
}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {

    std::fstream mapFile;
    cout << "current dir: " << std::filesystem::current_path() << "\n";
    mapFile.open("map.map");
    
    int srcX, srcY;
    std::cout <<path << "\n";
    if(!mapFile.is_open()){
        std::cout << "error open file\n";
        return;
    }
    cout << "open file success!\n";


    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            char c;
            mapFile.get(c);
            
            srcY = atoi(&c)*32;
            mapFile.get(c);
            
            srcX = atoi(&c)*32;
            
            
            Game::AddTile(srcX,srcY,x*32,y*32);
            mapFile.ignore();
        }
    }

    mapFile.close();
}



