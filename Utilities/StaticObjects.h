#ifndef GAME_STATICOBJECTS_H
#define GAME_STATICOBJECTS_H

#include "SDL.h"
#include "MusicController.h"
#include <vector>

using namespace std;

class StaticObjects {
public:
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static MusicController* musicController;

};


#endif //GAME_STATICOBJECTS_H
