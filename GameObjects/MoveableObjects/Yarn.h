//
// Created by Saad Zubairi on 12/11/2022.
//

#ifndef GAME_YARN_H
#define GAME_YARN_H


#include "../GameObject.h"

class Yarn : public GameObject{
public:
    Yarn(int x, int y, int dir);
    ~Yarn();
    void Move() override;
    int dir;
    int life = 30;
};


#endif //GAME_YARN_H
