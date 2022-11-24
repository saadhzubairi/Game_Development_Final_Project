#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main(int argc, char *argv[]) {
    game = new Game();

    game->init("MY Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1000, 800, false );

    while (game->Running()){
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
