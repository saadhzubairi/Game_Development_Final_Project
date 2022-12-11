//
// Created by Saad Zubairi on 12/11/2022.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include "../GameObject.h"

class Button : public GameObject{
public:
    Button(int x, int y);
    ~Button();
    int k;
};


#endif //GAME_BUTTON_H
