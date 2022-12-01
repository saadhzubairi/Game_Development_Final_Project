#pragma once
#include "SDL.h"
#include "TextureManager.h"

class Field {
public:
    Field();
    ~Field();

    void loadMap(int arr[25][40]);
    void drawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture* grass;
    SDL_Texture* grass_alt;
    SDL_Texture* grass_alt2;

    int map [25][35];


};

/*#include "SDL.h"

class Map {
public:
    Map();
    ~Map();

    void loadMap(int arr[25][35]);
    void drawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* dirt;

    int map [25][35];

};
*/