#include "TextureManager.h"

SDL_Texture *TextureManager::LoadTexture(const char *fn) {
    SDL_Surface *tmpSurf = IMG_Load(fn);
    SDL_Texture *text = SDL_CreateTextureFromSurface(StaticObjects::renderer, tmpSurf);
    SDL_FreeSurface(tmpSurf);
    return text;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect srcR, SDL_Rect destR) {
    SDL_RenderCopy(StaticObjects::renderer, tex, &srcR, &destR);
}

SDL_Texture *TextureManager::LoadSprite(const char *fn, int sheetSizeX, int sheetSizeY,int rows, int cols, SDL_Rect *spriteSourceRects) {
    SDL_Texture *text = LoadTexture(fn);
    int num = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            spriteSourceRects[num].x = sheetSizeX / cols * j;
            spriteSourceRects[num].y = sheetSizeY / rows * i;
            spriteSourceRects[num].h = sheetSizeY / rows;
            spriteSourceRects[num].w = sheetSizeX / cols;
            num++;
        }
    }
    return text;
}