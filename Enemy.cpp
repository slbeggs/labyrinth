#pragma once
#include "Enemy.h"
Enemy::Enemy(int hp, Cell* actorLoc): GameActor( hp,  actorLoc) {
    this->hp = hp;
    this->actorLoc = actorLoc;
    bool isAlive = true;
}
int Enemy::attack(GameActor* target) {
    srand(time(0));
    int attack = (rand() % 11) + 10;      // generating a random number from 10 to 20
    if (attack == 13 || attack == 17)
        return 0;
    target->hp -= attack;
    return attack;
}
 Enemy::~Enemy() {
     std::cout << "Enemy remains discarded \n";
 }



