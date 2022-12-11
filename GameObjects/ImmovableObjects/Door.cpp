//
// Created by Saad Zubairi on 12/11/2022.
//


#include "Door.h"

Door::Door(int x, int y) : GameObject("../Assets/Immovable/door.png", x, y, 24, 72, 1, 1, 1,2) {
    k = Track::DOOR_K;
    Track::DOOR_K++;
}

Door::~Door() {}

void Door::Move() {
    xPos += (int)tX;
    yPos += (int)tY;
    tX *= fric;
    tY *= fric;
    if(openAni){
        if (angle <= -89)
            openAni = false;
        angle--;
        if(Track::FRAME%2==0)   Translate(1,-1);
    }
}

void Door::OpenDoor() {
    if (angle <= -90)
        openAni = false;
    else openAni = true;
}

void Door::Render() {
        SDL_RenderCopyEx(StaticObjects::renderer, objTexture, &spriteSourceRects[Track::SPRITE % this->NumOfSprites], &destR, angle, NULL, SDL_FLIP_NONE);
}
