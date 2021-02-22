#include "game.h"
#include "player.h"
#include "alien.h"
#include "map.h"


Game::Game(std::string filepathMap) : roundCount(0) {
    map = new Map(filepathMap);
    char temp;
    for(unsigned int iy = 0; iy < map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < map->vec[iy].size(); ix++) {
            temp = map->vec[iy][ix];
            if      (temp == '*')   {
                 player = new Player(ix, iy); 
                 map->vec[iy][ix] = ' ';
            }
            else if (temp == 'g')   {
                aliens.push_back(new stupidAlien(ix, iy, map));
                map->vec[iy][ix] = '.';
            }
            // noch nicht implementiert
            // else if (temp == 'G') {
            //     aliens.push_back(new smartAlien(ix, iy, map));
            //     map->vec[iy][ix] = ' ';
            // }
        }
    }
}


Game::~Game() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        delete aliens[i];
    }
    delete player;
    delete map;
}

bool Game::alive() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        if ( aliens[i]->getXPosition() == player->getXPosition()
                                &&
             aliens[i]->getYPosition() == player->getXPosition() ) {
                 return false;
             }
    }
    return true;
}

void Game::update() {
    roundCount++;
    if (map->vec[player->getYPosition()][player->getXPosition()] == '.') {
        map->vec[player->getYPosition()][player->getXPosition()] = ' ';
    }
}

void Game::movePlayer(int userInput) {
    int x = player->getXPosition();
    int y = player->getYPosition();
    if      (userInput == 1) { 
        if (map->isFree(x-1, y)) { player->moveLeft(); }
    }
    else if (userInput == 2) { 
        if (map->isFree(x+1, y)) { player->moveRight(); }
    }
    else if (userInput == 3) { 
        if (map->isFree(x, y-1)) { player->moveUp(); }
    }
    else if (userInput == 4) { 
        if (map->isFree(x, y+1)) { player->moveDown(); }
    }
    // noch nicht implementiert:
    // else: keep moving ...
}


void Game::moveAliens() {
    for (unsigned int i = 0; i < aliens.size(); i++) {
        aliens[i]->move();
    }
}
