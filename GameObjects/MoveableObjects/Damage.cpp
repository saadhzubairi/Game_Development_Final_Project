#include "Damage.h"

Damage::Damage(int x, int y, int dir) : GameObject("../Assets/Immovable/hit.png", x, y, 192, 256, 4, 3, 1, 20) {
    this->dir = dir;
}

Damage::~Damage() {}

void Damage::Render() {
    if (Track::FRAME % 3 == 0) Life++;
    if (Life <= 2)
        SDL_RenderCopy(StaticObjects::renderer, objTexture, &spriteSourceRects[Life + 4 * dir], &destR);
    else
        alive = false;
}

void Damage::Move() {
    xPos += (int) tX;
    yPos += (int) tY;
    tX *= fric;
    tY *= fric;
    Translate(0,-5);
}
