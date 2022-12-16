//
// Created by Saad Zubairi on 12/13/2022.
//

#include <cstdio>
#include "MusicController.h"

MusicController::MusicController() {
    this->BgMusic = Mix_LoadMUS("../Assets/music.mp3");
    this->gameover = Mix_LoadWAV("../Assets/gameover.wav");
    this->catNoise = Mix_LoadWAV("../Assets/catnoise.wav");
    this->bigcatNoise = Mix_LoadWAV("../Assets/bigcat.wav");
    this->door = Mix_LoadWAV("../Assets/door.wav");
    this->doorButton = Mix_LoadWAV("../Assets/doorbutton.wav");
    this->bossLevel = Mix_LoadWAV("../Assets/bossLevel.wav");

    this->catLoose = Mix_LoadWAV("../Assets/catbutloose.wav");
    this->lifeGone = Mix_LoadWAV("../Assets/lifegone.wav");
    this->shoot = Mix_LoadWAV("../Assets/shoot.wav");
}

MusicController::~MusicController() {}

void MusicController::playBgMusic() {
    if (BgMusic == NULL) { printf("nothing here...\n"); }
    Mix_PlayMusic(BgMusic, -1);
}

void MusicController::playCatNoise() {
    Mix_PlayChannel(-1, catNoise, 0);
}

void MusicController::playBigCatNoise() {
    Mix_PlayChannel(-1, bigcatNoise, 0);
}

void MusicController::playDoor() {
    Mix_PlayChannel(-1, door, 0);
}

void MusicController::playDoorButton() {
    Mix_PlayChannel(-1, doorButton, 0);
}

void MusicController::playBossLevel() {
    Mix_PlayChannel(-1, bossLevel, 0);
}

void MusicController::playCatLoose() {
    Mix_PlayChannel(-1, catLoose, 0);
}

void MusicController::playLifeGone() {
    Mix_PlayChannel(-1, lifeGone, 0);
}

void MusicController::playShoot() {
    Mix_PlayChannel(-1, shoot, 0);
}

void MusicController::playGameOver() {
    Mix_PlayChannel(-1, gameover, 0);
}
