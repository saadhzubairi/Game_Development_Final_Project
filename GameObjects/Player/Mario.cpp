#include <cstdio>
#include "Mario.h"

Mario::Mario(int x, int y) :
        GameObject("C:\\Users\\Saad Zubairi\\CLionProjects\\Game\\Assets\\Mario.png", x, y, 256, 256, 4, 4, 2) {
this->fric = 0;
}

Mario::~Mario() {}

void Mario::Move() {
    xPos += (int) tX;
    yPos += (int) tY;
    tX *= fric;
    tY *= fric;
    if (xVel != 0 || yVel != 0) { GameObject::Translate(xVel, yVel); }
}

void Mario::Render() {
    int x;
    if (xVel != 0 || yVel != 0)
        x = (Track::SPRITE % 4) + 4 * move;
    else x = 4 * move;

    SDL_RenderCopy(StaticObjects::renderer, objTexture, &spriteSourceRects[x], &destR);
}
