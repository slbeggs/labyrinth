//#pragma once
#ifndef _enemy_
#define _enemy_
#include "GameActor.h"

class Enemy : public GameActor
{   public:  
	Enemy(int hp, Cell* actorLoc);
	// if dead
	~Enemy();
	int attack(GameActor* target);
};

#endif