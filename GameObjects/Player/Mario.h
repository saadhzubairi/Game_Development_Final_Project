#ifndef GAME_MARIO_H
#define GAME_MARIO_H

#include "../GameObject.h"
#include "../../Utilities/Track.h"

class Mario : public GameObject {
public:
    Mario(int x, int y);

    ~Mario();

    void Move();

    void Render();

    void Update();

    int xVel = 0;
    int yVel = 0;
    int move = 0;
};


#endif //GAME_MARIO_H
