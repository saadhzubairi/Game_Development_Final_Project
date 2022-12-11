//
// Created by Saad Zubairi on 12/11/2022.
//

#include "Button.h"

Button::Button(int x, int y) : GameObject("../Assets/Immovable/button.png", x, y, 24, 24, 1, 1, 1,3) {
    k = Track::BUTTON_K;
    Track::BUTTON_K++;
}

Button::~Button() {

}