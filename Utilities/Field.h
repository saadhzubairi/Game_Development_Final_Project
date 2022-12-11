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
    int map [25][40];
};
