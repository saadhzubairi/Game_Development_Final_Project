#include "Game.h"
#include "Utilities/StaticObjects.h"
#include "GameObjects/Player/Mario.h"

Mario* mario;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int w, int h, bool fullscreen) {

    Track::HEIGHT = h;
    Track::WIDTH = w;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, fullscreen);
        StaticObjects::renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(StaticObjects::renderer, 255, 255, 255, 255);
        isRunning = true;
    } else isRunning = false;

    mario = new Mario(500,400);
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_DOWN: mario->yVel     = 5; mario->move=0; break;
            case SDLK_LEFT: mario->xVel     =-5; mario->move=1; break;
            case SDLK_RIGHT:mario->xVel     = 5; mario->move=2; break;
            case SDLK_UP:   mario->yVel     =-5; mario->move=3; break;
            default:break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT:mario->xVel = 0;break;
            case SDLK_LEFT: mario->xVel = 0;break;
            case SDLK_UP:   mario->yVel= 0;break;
            case SDLK_DOWN: mario->yVel = 0;break;
            default:break;
        }
    }
}

void Game::Update() {
    mario->Update();
    mario->Move();
}

void Game::Render() {
    SDL_RenderClear(StaticObjects::renderer);
    mario->Render();
    SDL_RenderPresent(StaticObjects::renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(StaticObjects::renderer);
    SDL_Quit();
}