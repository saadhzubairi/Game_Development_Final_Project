#include "Game.h"
#include "StaticLists.h"
#include "Map.h"
#include "UIElementsForGame/UIButtons.h"
#include "GameObjects/ImmovableObjects/Button.h"
#include "GameObjects/ImmovableObjects/Door.h"
#include "GameObjects/MoveableObjects/Yarn.h"
#include "GameObjects/MoveableObjects/Disperse.h"
#include "GameObjects/MoveableObjects/DisperseBig.h"
#include "GameObjects/MoveableObjects/Damage.h"
#include "UIElementsForGame/Screen.h"

Field *field;
Map *map;
Mario *mario;
UIButtons *exitButton;
UIButtons *restartButton;
UIButtons *StartButton;

int Game::waiter = 0;
bool Game::waiter_start = false;


Screen *screen;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Track::WIDTH, Track::HEIGHT, Track::FULLSCREEN);
        StaticObjects::renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(StaticObjects::renderer, 255, 255, 255, 255);
        TTF_Init();
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)<0){
            printf("mix error: %s\n",Mix_GetError());
        };
        isRunning = true;
    } else isRunning = false;

    musicController = new MusicController();
    musicController->playBgMusic();

    exitButton = new UIButtons("Exit", Track::WIDTH - 100, Track::HEIGHT - 100, 20);
    restartButton = new UIButtons("restart", Track::WIDTH - 300, Track::HEIGHT - 100, 20);
    StartButton = new UIButtons("START", Track::WIDTH / 2, Track::HEIGHT / 2, 40);
    field = new Field();
    screen = new Screen();
}

void Game::HandleEvents() {
    SDL_PollEvent(&StaticObjects::event);
    if (Track::PLAYSTART) {
        int tileX = mario->yPos / (24);
        int tileY = mario->xPos / (24);
        if (StaticObjects::event.type == SDL_QUIT) { isRunning = false; }
        else if (StaticObjects::event.type == SDL_KEYDOWN && StaticObjects::event.key.repeat == 0) {
            switch (StaticObjects::event.key.keysym.sym) {
                case SDLK_DOWN:
                    mario->yVel = Track::PLAYER_SPEED;
                    mario->move = 0;
                    break;
                case SDLK_LEFT:
                    mario->xVel = -Track::PLAYER_SPEED;
                    mario->move = 1;
                    break;
                case SDLK_RIGHT:
                    mario->xVel = Track::PLAYER_SPEED;
                    mario->move = 2;
                    break;
                case SDLK_UP:
                    mario->yVel = -Track::PLAYER_SPEED;
                    mario->move = 3;
                    break;
                case SDLK_q:
                    Track::EXIT = 1;
                    break;
                case SDLK_SPACE:
                    StaticLists::shotsList.push_back(new Yarn(mario->xPos, mario->yPos, mario->move));
                    musicController->playShoot();
                    break;
                default:
                    break;
            }
        } else if (StaticObjects::event.type == SDL_KEYUP && StaticObjects::event.key.repeat == 0) {
            switch (StaticObjects::event.key.keysym.sym) {
                case SDLK_RIGHT:
                    mario->xVel = 0;
                    break;
                case SDLK_LEFT:
                    mario->xVel = 0;
                    break;
                case SDLK_UP:
                    mario->yVel = 0;
                    break;
                case SDLK_DOWN:
                    mario->yVel = 0;
                    break;
                default:
                    break;
            }
        } else if (StaticObjects::event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            bool quit = exitButton->HandleButtonClickEventsFromMouse(x, y);
            if (quit) Track::EXIT = 1;
        } else if (StaticObjects::event.type == SDL_MOUSEMOTION) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            exitButton->HandleHoverEffects(x, y);
        }

        if (map->map[tileX + 1][tileY] == 1 || map->map[tileX + 1][tileY] == 2) {
            mario->yVel = 0.1;
            mario->Translate(0, -1);
        }
        if (map->map[tileX][tileY - 1] == 1 || map->map[tileX][tileY - 1] == 2) {
            mario->xVel = 0.1;
            mario->Translate(1, 0);
        }
        if (map->map[tileX][tileY + 1] == 1 || map->map[tileX][tileY + 1] == 2) {
            mario->xVel = 0.1;
            mario->Translate(-1, 0);
        }
        if (map->map[tileX - 1][tileY] == 1 || map->map[tileX - 1][tileY] == 2) {
            mario->yVel = 0.1;
            mario->Translate(0, 1);
        }
    }
    else if (Track::MENU_MAIN) {
        if (StaticObjects::event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            bool quit = exitButton->HandleButtonClickEventsFromMouse(x, y);
            if (quit) Track::EXIT = 1;
            bool start = StartButton->HandleButtonClickEventsFromMouse(x, y);
            if (start) {
                Track::MENU_MAIN = false;
                Track::PLAYSTART = true;
                startGame();
            }
            bool restart = restartButton->HandleButtonClickEventsFromMouse(x, y);
            if(restart) { startGame();
                printf("pressed here");}

        } else if (StaticObjects::event.type == SDL_MOUSEMOTION) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            exitButton->HandleHoverEffects(x, y);
        }
    }
}

void Game::Update() {
    if (Track::PLAYSTART) {
        for (GameObject *gameObject: StaticLists::gameObjectsList) {
            gameObject->Update();
            gameObject->Move();
        }
        for (GameObject *gameObject: StaticLists::shotsList) {
            gameObject->Update();
            gameObject->Move();
        }
        mario->Update();
        mario->Move();
        StaticLists::uiLabelsList.at(1)->SetText(to_string(Track::EVILCATKILL));
        StaticLists::uiLabelsList.at(3)->SetText(to_string(Track::LEVEL));
        StaticLists::uiLabelsList.at(5)->SetText(to_string(Track::PLAYERHEALTH));
        StaticLists::uiLabelsList.at(7)->SetText(to_string(Track::TIMEREM / 60));
        Track::TIMEREM--;
    }

    if(Track::PLAYERHEALTH <= 0 || Track::TIMEREM <= 0){
        waiter_start = true;
    }

    if(waiter_start){
        if(waiter==0)
        musicController->playGameOver();
        waiter++;
        mario->xVel = 0;
        mario->yVel = 0;
        StaticLists::gameObjectsList.push_back(new Damage(mario->xPos, mario->yPos, mario->move));
    }

    if(waiter >= 75){
        Track::PLAYSTART = false;
        Track::MENU_MAIN = true;
    }
}

void Game::Render() {
    SDL_RenderClear(StaticObjects::renderer);
    field->drawMap();
    if (Track::PLAYSTART) {
        for (GameObject *gameObject: StaticLists::shotsList) {
            gameObject->Render();
        }
        for (GameObject *gameObject: StaticLists::gameObjectsList) {
            gameObject->Render();
        }
        mario->Render();
        for (UILabel *uiLabel: StaticLists::uiLabelsList) {
            uiLabel->Render();
        }
        restartButton->Render();
    } else if (Track::MENU_MAIN) {
        screen->Render();
        StartButton->Render();
    }
    exitButton->Render();

    SDL_RenderPresent(StaticObjects::renderer);

}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(StaticObjects::renderer);
    SDL_Quit();
}

void Game::CheckDoorButtons() {
    if (Track::PLAYSTART) {
        for (GameObject *gameObject: StaticLists::gameObjectsList) {
            if (gameObject->type == 3) {
                if (CheckCollisions(mario, gameObject)) {
                    int key = ((Button *) gameObject)->k;
                    //now look for the door
                    for (GameObject *doorFound: StaticLists::gameObjectsList) {
                        if (doorFound->type == 2) {
                            if (((Door *) doorFound)->k == key) {
                                ((Door *) doorFound)->OpenDoor();
                                int x = doorFound->xPos / 24;
                                int y = doorFound->yPos / 24;
                                map->map[y][x] = 0;
                                musicController->playDoorButton();
                            }
                        }
                    }
                }
            }
        }

        for (GameObject *yarn: StaticLists::shotsList) {
            for (GameObject *animal: StaticLists::gameObjectsList) {

                if (animal->type == 8) {
                    if (CheckCollisions(animal, yarn)) {
                        animal->alive = false;
                        yarn->alive = false;
                        Track::EVILCATKILL++;
                        StaticLists::gameObjectsList.push_back(new Disperse(animal->xPos, animal->yPos));
                        musicController->playCatNoise();
                    }
                }

                if (animal->type == 30) {
                    if (CheckCollisions(yarn, animal)) {
                        yarn->alive = false;
                        animal->TakeD();
                        musicController->playBigCatNoise();
                        StaticLists::gameObjectsList.push_back(new DisperseBig(animal->xPos, animal->yPos));
                    }
                }

            }
        }

        for (GameObject *animal: StaticLists::gameObjectsList) {
            if (animal->type == 8) {
                if (CheckCollisions(animal, mario)) {
                    musicController->playCatLoose();
                    musicController->playLifeGone();
                    animal->alive = false;
                    Track::PLAYERHEALTH--;
                    StaticLists::gameObjectsList.push_back(new Damage(mario->xPos, mario->yPos, mario->move));
                    StaticLists::gameObjectsList.push_back(new Disperse(animal->xPos, animal->yPos));
                }
            }
        }
    }
}


bool Game::CheckCollisions(GameObject *GO1, GameObject *GO2) {
    if ((GO1->xMin >= GO2->xMin && GO1->xMin <= GO2->xMax) || (GO2->xMin >= GO1->xMin && GO2->xMin <= GO1->xMax)) {
        if ((GO1->yMin >= GO2->yMin && GO1->yMin <= GO2->yMax) || (GO2->yMin >= GO1->yMin && GO2->yMin <= GO1->yMax)) {
            return true;
        }
    }
    return false;
}

void Game::KillDead() {

    for (int i = 0; i < StaticLists::shotsList.size(); ++i) {
        if (!StaticLists::shotsList.at(i)->isAlive()) {
            GameObject *gameok = StaticLists::shotsList.at(i);
            StaticLists::shotsList.erase(StaticLists::shotsList.begin() + i);
            delete gameok;
        }
    }

    for (int i = 0; i < StaticLists::gameObjectsList.size(); ++i) {
        if (!StaticLists::gameObjectsList.at(i)->isAlive()) {
            GameObject *gameok = StaticLists::gameObjectsList.at(i);
            StaticLists::gameObjectsList.erase(StaticLists::gameObjectsList.begin() + i);
            delete gameok;
        }
    }
}

void Game::startGame() {

    StaticLists::gameObjectsList.clear();
    StaticLists::uiLabelsList.clear();

    map = new Map();

    StaticLists::uiLabelsList.push_back(new UILabel("Evil Cats Killed: ", 170, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("0", 330, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("Level: ", 500, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("0", 580, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("Health: ", 800, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("0", 900, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("Time Left: ", 1100, 20, 20));
    StaticLists::uiLabelsList.push_back(new UILabel("0", 1200, 20, 20));

    Track::PLAYSTART = true;
    Track::EVILCATKILL = 0;
    Track::PLAYERHEALTH = 100;
    Track::LEVEL = 0;
    Track::TIMEREM = 3600;
    waiter_start = false;
    waiter = 0;


    mario = new Mario(24, 120);
}
