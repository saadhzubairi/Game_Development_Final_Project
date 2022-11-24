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
    game->init("MY Game", 1000, 800, false);

    while (game->Running()) {

        Track::FRAME++;
        if (!(Track::FRAME % 3)) Track::SPRITE++;

        FrameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        FrameTime = SDL_GetTicks() - FrameStart;

        if (FrameDelay > FrameTime) {
            SDL_Delay(FrameDelay - FrameTime);
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
