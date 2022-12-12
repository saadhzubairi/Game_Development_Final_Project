//
// Created by Saad Zubairi on 12/13/2022.
//

#ifndef GAME_EVILCAT_H
#define GAME_EVILCAT_H


#include "../GameObject.h"

class EvilCat : public GameObject{
public:
    EvilCat(int x, int y);
    ~EvilCat();
    void Move();
    void TakeD();
    int life = 10;
};


#endif //GAME_EVILCAT_H
