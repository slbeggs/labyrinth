#pragma once
using namespace std;
#include <iostream>
#include <stack>
#include <vector>
#include "Cell.h";
// randomly generated dungen
//Maze like dungen made up by a grid of cells 
class Maze {
	public:
	int  mazeWidth;
	int  mazeHeight;
	Cell head;
	stack<Cell*> mazeStack;	// Cells in a path
	int  numOfVisitedCells; //Cells visited by random path maker
	//inializes maze
	Maze(int width, int height);
	// create a horizonital link between two cells
	void linkH(Cell* left, Cell* right);
	// create a vertical link between two cells
	void linkV(Cell* below, Cell* above);
	// creates a randomly Generated maze in cell grid
	void setMazePath();
	Cell* setEndPoints();// set where the player starts and desitation
};

