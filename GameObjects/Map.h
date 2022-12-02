#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "SDL.h"
#include "../Utilities/TextureManager.h"

class Map {
public:
    Map();
    ~Map();

    void loadMap(int arr[25][35]);
    void drawMap();

private:
    int map [25][35];
};


#endif //GAME_MAP_H
