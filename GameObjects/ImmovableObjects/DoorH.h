//
// Created by Saad Zubairi on 12/11/2022.
//

#ifndef GAME_DOORH_H
#define GAME_DOORH_H


#include "../GameObject.h"

class Door : public GameObject {
public:
    Door(int x, int y);

    ~Door();

    void Move();

    void Render();

    void OpenDoor();

    int k;
    double angle = 0;
    bool openAni = false;
};



#endif //GAME_DOORH_H
