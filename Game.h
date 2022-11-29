#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"

class Game {
public:
    Game();
    ~Game();
    void init(const char *title, int w, int h, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running() { return isRunning;};

private:
    bool isRunning;
    SDL_Window *window;
};

#endif //GAME_GAME_H
