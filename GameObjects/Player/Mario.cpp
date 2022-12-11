#include <cstdio>
#include "Mario.h"

Mario::Mario(int x, int y) : GameObject("../Assets/Mario.png", x, y, 256, 256, 4, 4, 1,0) {
    this->fric = 0;
}

Mario::~Mario() {}

void Mario::Move() {
    xPos += (int) tX;
    yPos += (int) tY;
    tX *= fric;
    tY *= fric;
    if (xVel != 0 || yVel != 0) {
        GameObject::Translate(xVel, yVel);
    }
}

void Mario::Render() {
    int x;
    if (xVel != 0 || yVel != 0) x = (Track::SPRITE % 4) + 4 * move;
    else x = 4 * move;
    SDL_RenderCopy(StaticObjects::renderer, objTexture, &spriteSourceRects[x], &destR);
}

void Mario::Update() {
    destR.h = this->ObjHeight;
    destR.w = this->ObjWidth;
    destR.x = xPos - destR.w / 2;
    destR.y = yPos - destR.h / 2;

    this->xMin = xPos - ObjWidth / 2 + 16;
    this->xMax = xMin + ObjWidth-16;
    this->yMin = yPos - ObjHeight / 2 + 10;
    this->yMax = yMin + ObjHeight;
}