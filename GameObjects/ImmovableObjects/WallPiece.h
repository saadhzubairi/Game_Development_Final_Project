#ifndef GAME_WALLPIECE_H
#define GAME_WALLPIECE_H

#include "../GameObject.h"

class WallPiece : public GameObject{
public:
    WallPiece(int x, int y);
    ~WallPiece();
};


#endif //GAME_WALLPIECE_H
