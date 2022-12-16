#ifndef GAME_DISPERSEBIG_H
#define GAME_DISPERSEBIG_H


#include "../GameObject.h"

class DisperseBig : public GameObject{
public:
    DisperseBig(int x, int y);
    ~DisperseBig();
    void Render() override;
    int Life = 0;
    int cSprite = 0;
};


#endif //GAME_DISPERSEBIG_H
