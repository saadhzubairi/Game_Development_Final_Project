#include "DisperseBig.h"

DisperseBig::DisperseBig(int x, int y) : GameObject("../Assets/Immovable/boom.png", x, y, 640, 256, 2, 5, 3, 41) {}

DisperseBig::~DisperseBig() {}

void DisperseBig::Render() {
    SDL_RenderCopy(StaticObjects::renderer, objTexture, &spriteSourceRects[cSprite], &destR);
    Life++;
    if (Life % 2 == 0) cSprite++;
    if (Life > 20) { alive = false; }
}
