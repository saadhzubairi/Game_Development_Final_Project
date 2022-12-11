#ifndef GAME_STATICOBJECTS_H
#define GAME_STATICOBJECTS_H

#include "SDL.h"
#include <vector>

using namespace std;

class StaticObjects {
public:
    static SDL_Renderer *renderer;
    static SDL_Event event;
};


#endif //GAME_STATICOBJECTS_H
