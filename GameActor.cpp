#pragma once
#include "GameActor.h";
#include "Cell.h"
GameActor::GameActor(int hp , Cell* actorLoc ) {
    this->hp = hp;
    this->actorLoc = actorLoc;
    bool isAlive = true;
    this->weaponModifier = 1;
    (this->bag).hasSword = false;
    (this->bag).hasSword = false;
};
GameActor::GameActor() {
     isAlive = true;
}
int GameActor::attack(GameActor* target) {
   
     std::cout << "empty game object";
     return 0;
}
int GameActor::heal() {
    if (this->bag.hasPotion) {
        int incr = 25;

        // Max HP can't be greater than 200.
        if ( hp + 25 <= 200)
            this->hp += 25;
        else {
            incr = 200 - hp;
            hp = 200;
        }

        (this->bag).hasPotion = false;      // after healing potion is spent
        return incr;
    }
    else
        return -1;

}

