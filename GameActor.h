//#pragma once
#ifndef _gameActor_
#define _gameActor_
#include <iostream>
//#include <string>
//#include <stdlib.h>     // for rand() and srand()
//#include <time.h> 
#include "Cell.h"

//Base class of enemy and player
class GameActor
{
//inventory
protected:struct Bag  {
bool hasSword;
bool hasPotion;

};
//protected:

public:
	bool isAlive;
	int hp;
	int weaponModifier;
	Bag bag;
	Cell * actorLoc = new Cell();
	 GameActor(int hp , Cell* actorLoc);
	 GameActor();
	 int heal();
	 virtual int attack(GameActor* target);




};
#endif 