#pragma once
#include "Cell.h"
#include "Enemy.h"

//#include "Enemy.h";
#include <iostream>
using namespace std;
// center cells

Cell::Cell(int xLoc, int yLoc) {
	this->xLoc = xLoc;
	this->yLoc = yLoc;
	visited = false;
	hasPathUp = false;
	hasPathDown = false;
	hasPathLeft = false;
	hasPathRight =false;
	isMazeEnd = false;
	hasEnemy = rand() % 2;
	//hasEnemy = false;
	//cellGuard = new Enemy(300,this);


	//spawnEnemy();
}
Cell::Cell() {
	visited = false;
	hasPathUp = false;
	hasPathDown = false;
	hasPathLeft = false;
	hasPathRight = false;
	isMazeEnd = false;
	hasEnemy = rand() % 2;
	//hasEnemy = true;
	//hasEnemy = false;
}
void Cell::printCell() {
	cout << endl;
	cout << "Loc:(" << xLoc << "," << yLoc << ") " << endl;
	
	
	if (hasPathUp) 
		cout << "press 1 to go north" << endl;
	else 
		cout << "north path blocked" << endl;
	if (hasPathRight)
		cout << "press 2 to go east" << endl;
	else
		cout << "east path blocked" << endl;
	if (hasPathDown)
		cout << "press 3 to go south" << endl;
	else
		cout << "south path blocked" << endl;
	if (hasPathLeft)
		cout << "press 4 to go west" << endl;
	else
		cout << "west path blocked" << endl;
}

