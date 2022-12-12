#include "Disperse.h"

Disperse::Disperse(int x, int y) : GameObject("../Assets/Immovable/boom.png", x, y, 640, 256, 2, 5, 1, 21) {}

Disperse::~Disperse() {}

void Disperse::Render() {
    SDL_RenderCopy(StaticObjects::renderer, objTexture, &spriteSourceRects[cSprite], &destR);
    Life++;
    if (Life % 6 == 0) cSprite++;
    if (Life > 60) { alive = false; }
}
