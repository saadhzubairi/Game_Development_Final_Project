//
// Created by Saad Zubairi on 12/11/2022.
//

#include "Animal.h"

Animal::Animal(int x, int y, int n) : GameObject("../Assets/Movable/animalone.png", x, y, 256, 256, 4, 4, 1, 8) {
    switch (n) {
        case 1:
            setObjTexture("../Assets/Movable/animalone.png", 256, 256, 4, 4, 1);
            break;
        case 2:
            setObjTexture("../Assets/Movable/animaltwo.png", 256, 256, 4, 4, 1);
            break;
        case 3:
            setObjTexture("../Assets/Movable/animalthree.png", 256, 256, 4, 4, 1);
            break;
        case 4:
            setObjTexture("../Assets/Movable/animalfour.png", 256, 256, 4, 4, 1);
            break;
    }

    reveCheck = Track::FRAME%2;
}

Animal::~Animal() {
    printf("Cat Destroyed!");
}

void Animal::Move() {
    xPos += (int) tX;
    yPos += (int) tY;
    tX *= fric;
    tY *= fric;

    if (reveCheck == 0) {
        Translate(0, 1);
        stepCount++;
        if (stepCount > 25) reveCheck = 1;
        move = 0;
    } else {
        Translate(0, -1);
        stepCount--;
        if (stepCount < -25) reveCheck = 0;
        move = 3;
    }

}

void Animal::Render() {
    int x = (Track::SPRITE % 4) + 4 * move;
    SDL_RenderCopy(StaticObjects::renderer, objTexture, &spriteSourceRects[x], &destR);
}

void Animal::Update() {
    GameObject::Update();
}
