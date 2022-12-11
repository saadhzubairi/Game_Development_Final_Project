#include "Game.h"
#include "StaticLists.h"
#include "Map.h"
#include "UIElementsForGame/UIButtons.h"

Field *field;
Map *map;
Mario *mario;
UIButtons *exitButton;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int w, int h, bool fullscreen) {

    Track::HEIGHT = h;
    Track::WIDTH = w;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, fullscreen);
        StaticObjects::renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(StaticObjects::renderer, 255, 255, 255, 255);
        TTF_Init();
        isRunning = true;
    } else isRunning = false;

    field = new Field();
    map = new Map();
    exitButton = new UIButtons("Exit", Track::WIDTH/2, Track::HEIGHT/2, 20);
    mario = new Mario(24, 120);
}

void Game::HandleEvents() {
    int tileX = mario->yPos/(24);
    int tileY = mario->xPos/(24);

    SDL_PollEvent(&StaticObjects::event);
    if (StaticObjects::event.type == SDL_QUIT) {isRunning = false;}
    else if (StaticObjects::event.type == SDL_KEYDOWN && StaticObjects::event.key.repeat == 0) {
        switch (StaticObjects::event.key.keysym.sym) {
            case    SDLK_DOWN:      mario->yVel = Track::PLAYER_SPEED;  mario->move = 0;     break;
            case    SDLK_LEFT:      mario->xVel = -Track::PLAYER_SPEED; mario->move = 1;     break;
            case    SDLK_RIGHT:     mario->xVel = Track::PLAYER_SPEED;  mario->move = 2;     break;
            case    SDLK_UP:        mario->yVel = -Track::PLAYER_SPEED; mario->move = 3;     break;
            case    SDLK_q:         Track::EXIT = 1;                                         break;
            default:                                                                        break;}}
    else if (StaticObjects::event.type == SDL_KEYUP && StaticObjects::event.key.repeat == 0) {
        switch (StaticObjects::event.key.keysym.sym) {
            case    SDLK_RIGHT:     mario->xVel = 0;    break;
            case    SDLK_LEFT:      mario->xVel = 0;    break;
            case    SDLK_UP:        mario->yVel = 0;    break;
            case    SDLK_DOWN:      mario->yVel = 0;    break;
            default:                                    break;
        }
    }
    else if (StaticObjects::event.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        bool quit = exitButton->HandleButtonClickEventsFromMouse(x,y);
        if (quit) Track::EXIT = 1;
    }
    else if(StaticObjects::event.type == SDL_MOUSEMOTION){
        int x, y;
        SDL_GetMouseState(&x, &y);
        exitButton->HandleHoverEffects(x,y);
    }

    if ( map->map[tileX+1][tileY] == 1 ) { mario->yVel=0.1;mario->Translate( 0,-1); }
    if ( map->map[tileX][tileY-1] == 1 ) { mario->xVel=0.1;mario->Translate( 1, 0); }
    if ( map->map[tileX][tileY+1] == 1 ) { mario->xVel=0.1;mario->Translate(-1, 0); }
    if ( map->map[tileX-1][tileY] == 1 ) { mario->yVel=0.1;mario->Translate( 0, 1); }
}

void Game::Update() {
    for (GameObject* gameObject: StaticLists::gameObjectsList) {
        gameObject->Update();
        gameObject->Move();
    }
    mario->Update();
    mario->Move();

}

void Game::Render() {
    SDL_RenderClear(StaticObjects::renderer);
    field->drawMap();
    mario->Render();
    exitButton->Render();
    for (GameObject* gameObject: StaticLists::gameObjectsList) {
        gameObject->Render();
    }
    SDL_RenderPresent(StaticObjects::renderer);

}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(StaticObjects::renderer);
    SDL_Quit();
}

