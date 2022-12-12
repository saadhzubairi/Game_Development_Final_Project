#ifndef GAME_DAMAGE_H
#define GAME_DAMAGE_H


#include "../GameObject.h"

class Damage : public GameObject{
public:
    Damage(int x, int y, int dir);
    ~Damage();
    void Render() override;
    void Move();
    int dir;
    int Life = 0;
};


#endif //GAME_DAMAGE_H
