#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "SDL.h"
#include "SDL_image.h"
#include "../Utilities/TextureManager.h"
#include "../Utilities/StaticObjects.h"
#include "../Utilities/Track.h"

class GameObject {
public:
    GameObject(const char *textureSheet, int x, int y, int sheetSizeX, int sheetSizeY, int rows, int cols, double zoom, int type);
    ~GameObject();

    virtual void Render();
    virtual bool isAlive();
    virtual void Destroy();
    virtual void Move();
    virtual void Update();

    void Translate(int x, int y);

    int xPos, yPos;
    float fric, tX, tY;

    bool alive = true;

    void setObjTexture(const char *textureSheet, int sheetSizeX, int sheetSizeY, int rows, int cols, double zoom);

    SDL_Texture *objTexture;
    SDL_Rect destR;
    SDL_Rect spriteSourceRects[16];

    int NumOfSprites, ObjHeight, ObjWidth;
    int xMin, xMax;
    int yMin, yMax;

    int type;

    virtual void TakeD() {}
};


#endif //GAME_GAMEOBJECT_H
