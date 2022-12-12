//
// Created by Saad Zubairi on 12/13/2022.
//

#include "EvilCat.h"

EvilCat::EvilCat(int x, int y) : GameObject("../Assets/Immovable/EvilCat.png", x, y, 192, 64, 1, 3, 2, 30)  {

}

EvilCat::~EvilCat() {

}

void EvilCat::Move() {
    xPos += (int)tX;
    yPos += (int)tY;
    tX *= fric;
    tY *= fric;

    int x = sin(Track::SPRITE)*10;

    Translate(0,x);
    if(life<=0){
        alive = false;
    }
}

void EvilCat::TakeD() {
    life--;
}
