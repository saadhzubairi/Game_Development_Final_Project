#ifndef GAME_STATICLISTS_H
#define GAME_STATICLISTS_H

#include "GameObjects/GameObject.h"
#include "UIElementsForGame/UILabel.h"

class StaticLists {
public:
    static vector<GameObject*> gameObjectsList;
    static vector<GameObject*> shotsList;
    static vector<UILabel*> uiLabelsList;

};

#endif //GAME_STATICLISTS_H
