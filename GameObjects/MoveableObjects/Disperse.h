#ifndef GAME_DISPERSE_H
#define GAME_DISPERSE_H


#include "../GameObject.h"

class Disperse : public GameObject{
public:
    Disperse(int x, int y);
    ~Disperse();
    void Render() override;
    int Life = 0;
    int cSprite = 0;
};


#endif //GAME_DISPERSE_H
