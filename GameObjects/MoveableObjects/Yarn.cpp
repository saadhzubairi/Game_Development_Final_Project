//
// Created by Saad Zubairi on 12/11/2022.
//

#include "Yarn.h"

Yarn::Yarn(int x, int y, int dir) : GameObject("../Assets/Movable/shot.png", x, y, 72, 24, 1, 3, 1, 12){
    this->dir = dir;
}

Yarn::~Yarn() {

}

void Yarn::Move() {
    xPos += (int) tX;
    yPos += (int) tY;
    tX *= fric;
    tY *= fric;

    switch (dir) {
        case 0:
            Translate(0,3);
            break;
        case 1:
            Translate(-3,0);
            break;
        case 2:
            Translate(3,0);
            break;
        case 3:
            Translate(0,-3);
            break;
        default:
            break;
    }

    life--;
    if(life <= 0){
        alive = false;
    }

}
