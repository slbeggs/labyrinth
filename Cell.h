#pragma once

// units of maze/dungen
//link together to form a grid
class Cell
{
public:

	//links to near by nodes
	Cell* upCell; //north path
	Cell* downCell;//south path
	Cell* leftCell; // west path
	Cell* rightCell;//east
	int xLoc;//x coordinate on grid     
	int yLoc;//y coordinate on grid(revese order) north = low, south = high
	bool hasEnemy;//is there  a enemy on this cell?
	bool isMazeEnd = false;// is cell final cell in maze?(game objective)
	// if false  path is blocked by  wall
	bool hasPathUp = false;
	bool hasPathDown = false;
	bool hasPathLeft = false;
	bool hasPathRight = false;
	bool visited;//cell has been visted by maze path setter(sets maze path to cell)
	

	Cell(int xLox, int yLoc);
	Cell();
	//show avaible paths and cell location
	void printCell();
	


};

