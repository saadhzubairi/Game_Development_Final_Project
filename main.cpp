#include <iostream>
#include "Game.h"
#include "Utilities/Track.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {

    const int FPS = 60;
    const int FrameDelay = 1000 / FPS;

    Uint32 FrameStart;
    int FrameTime;

    game = new Game();
    game->init("My Game", 1000, 700, false);

    while (game->Running()){
        Track::FRAME++;
        if (!(Track::FRAME % Track::SPRITEDELAY)) Track::SPRITE++;

        FrameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        FrameTime = SDL_GetTicks() - FrameStart;

        if (FrameDelay > FrameTime) {SDL_Delay(FrameDelay - FrameTime);}
    }
    return 0;
}
