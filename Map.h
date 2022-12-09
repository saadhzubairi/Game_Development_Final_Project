#ifndef GAME_MAP_H
#define GAME_MAP_H

class Map {
public:
    Map();
    ~Map();
    void loadMap(int arr[44][80]);
    void drawMap();
public:
    int map [80][44];
};

#endif //GAME_MAP_H
