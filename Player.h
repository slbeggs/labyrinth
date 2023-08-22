#pragma once
#include "Enemy.h"
//Stores player data and utilites
class Player : public GameActor
{
protected:
	
	//custom  player attack
	int attack(GameActor* target);
	//Combat mode of game
	void combat(GameActor* enemy);
	
public :
	//Transverse player across maze;
    // recursive -Calls movePlayer() till maze end has been found or player  dies
   // return Cells visted by player
	Player(int hp, Cell* actorLoc);
	Player();
	Cell movePlayer(Cell current);
	
};

