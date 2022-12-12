//
// Created by Saad Zubairi on 12/11/2022.
//

#ifndef GAME_DOOR_H
#define GAME_DOOR_H

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
    bool open = false;
};


#endif //GAME_DOOR_H
