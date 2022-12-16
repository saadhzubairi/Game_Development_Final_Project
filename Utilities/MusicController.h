#ifndef GAME_MUSICCONTROLLER_H
#define GAME_MUSICCONTROLLER_H

#include "SDL_mixer.h"

class MusicController {
public:
    MusicController();
    ~MusicController();

    Mix_Music *BgMusic = NULL;

    Mix_Chunk *catNoise = NULL;
    Mix_Chunk *bigcatNoise = NULL;
    Mix_Chunk *bossLevel = NULL;
    Mix_Chunk *door = NULL;
    Mix_Chunk *doorButton = NULL;

    Mix_Chunk *catLoose = NULL;
    Mix_Chunk *lifeGone = NULL;
    Mix_Chunk *shoot = NULL;



    void playDoorButton();
    void playDoor();
    void playCatNoise();
    void playBigCatNoise();
    void playBgMusic();
    void playBossLevel();

    void playCatLoose();
    void playLifeGone();
    void playShoot();

};


#endif //GAME_MUSICCONTROLLER_H
