#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include "Utilities/StaticObjects.h"
#include "GameObjects/Player/Mario.h"
#include "GameObjects/GameObject.h"
#include "Utilities/Field.h"

class Game {
public:
    Game();
    ~Game();
    void init(const char *title, int w, int h, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    void CheckDoorButtons();
    void KillDead();
    static bool CheckCollisions(GameObject *GO1, GameObject *GO2);
    bool Running() { return isRunning;};

private:
    bool isRunning;
    SDL_Window *window;

    static void startGame();

};

#endif //GAME_GAME_H
