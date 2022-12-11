#ifndef GAME_ANIMAL_H
#define GAME_ANIMAL_H

#include "../GameObject.h"

class Animal : public GameObject{
public:
    Animal(int x, int y, int n);

    ~Animal();

    void Move();

    void Render();

    void Update();

    int reveCheck = 0;
    int stepCount = 0;
    int move;
};


#endif //GAME_ANIMAL_H
