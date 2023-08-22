#pragma once
#include "Maze.h"

using namespace std;
// randomly generated dungen
//Maze like dungen made up by a grid of cells 

	//inializes maze
Maze::Maze(int width, int height)
{

	// Maze parameters
	mazeWidth = width;
	mazeHeight = height;

	// Choose a starting cell
	head = Cell(0, 0);
	Cell* current = &head;

	Cell* above = current;
	//inialize and connect all cells in grid
	for (int y = 0; y < mazeHeight; y++) {
		// holds start of row
		Cell* firstInRow = current;
		for (int x = 0; x < mazeWidth; x++) {
			Cell* next = new Cell(x + 1, y);
			linkH(current, next);
			if (y > 0) {
				linkV(current, above);
			}
			current = next;
			above = above->rightCell;
		}
		// moves below up by 1
		above = firstInRow;
		// beguins next row
		current = new Cell(0, y + 1);
	}
	// sets random cell
	int x = rand() % mazeWidth;
	int y = rand() % mazeHeight;
	//Cell start;


	mazeStack.push(&head);

	numOfVisitedCells = 1;


}
// create a horizonital link between two cells
void Maze::linkH(Cell* left, Cell* right) {
	left->rightCell = right;
	//(*left).hasPathRight = true;
	right->leftCell = left;
	//(*right).hasPathLeft = true;
}
// create a vertical link between two cells
void Maze:: linkV(Cell* below, Cell* above) {
	above->downCell = below;
	below->upCell = above;
}
//creates a randomly Generated maze in cell grid 
void Maze::setMazePath()
{

	// Do Maze Algorithm
	// randomly creates paths intill evey cell is accesble by player
	while (numOfVisitedCells < mazeWidth * mazeHeight)
	{
		// Create a set of unvisted neighbours
		vector<int> neighbours; //0 = north, 1 = east , 2 = south, 3 = east
		// North neighbour
		// checks if neighbour exists and is unvisted
		//current cell is  not the top row and next cell has not been visited
		if (mazeStack.top()->yLoc > 0 && !(mazeStack.top()->upCell->visited)) {
			neighbours.push_back(0);
		}
		// East neighbour
		if (mazeStack.top()->xLoc < mazeWidth - 1 && !(mazeStack.top()->rightCell->visited))
			neighbours.push_back(1);
		// South neighbour
		if (mazeStack.top()->yLoc < mazeHeight - 1 && !(mazeStack.top()->downCell->visited))
			neighbours.push_back(2);
		// West neighbour
		if (mazeStack.top()->xLoc > 0 && !(mazeStack.top()->leftCell->visited))
			neighbours.push_back(3);

		// Are there any neighbours available?
		if (!neighbours.empty())
		{

			// Choose one available neighbour at random
			int next_cell_dir = neighbours[rand() % neighbours.size()];
			// Create a path between the neighbour and the current cell
			switch (next_cell_dir)
			{
			case 0: // North
				// set cell to the north to be visted and has a south path
				mazeStack.top()->upCell->visited = true;
				mazeStack.top()->upCell->hasPathDown = true;
				mazeStack.top()->hasPathUp = true;
				mazeStack.push(mazeStack.top()->upCell);
				break;

			case 1: // East
				mazeStack.top()->rightCell->visited = true;
				mazeStack.top()->rightCell->hasPathLeft = true;
				mazeStack.top()->hasPathRight = true;
				mazeStack.push(mazeStack.top()->rightCell);
				break;

			case 2: // South
				mazeStack.top()->downCell->visited = true;
				mazeStack.top()->downCell->hasPathUp = true;
				mazeStack.top()->hasPathDown = true;
				mazeStack.push(mazeStack.top()->downCell);
				break;

			case 3: // West
				mazeStack.top()->leftCell->visited = true;
				mazeStack.top()->leftCell->hasPathRight = true;
				mazeStack.top()->hasPathLeft = true;
				mazeStack.push(mazeStack.top()->leftCell);
				break;

			}

			numOfVisitedCells++;

		}
		else
		{
			// No available neighbours so backtrack!
			mazeStack.pop();
		}
	}
}
Cell* Maze::setEndPoints()// set where the player starts and desitation 
{

	Cell* start = new Cell;
	Cell* current = &head;
	// cordinates of starting cell
	int startY = (rand() % mazeHeight) - 1;
	int startX = (rand() % mazeWidth) - 1;
	// cordinates of end cell
	int endY = (rand() % mazeHeight) - 1;
	int endX = (rand() % mazeWidth) - 1;
	// search grid for starting cell
	for (int y = 0; y < startY; y++) {
		;
		current = current->downCell;
	}

	for (int x = 0; x < startX; x++) {
		current = current->rightCell;
	}

	start = current;
	current = &head;
	// search  grid for end cell
	for (int y = 0; y < endY; y++) {
		current = current->downCell;
	}

	for (int x = 0; x < endX; x++) {
		current = current->rightCell;
	}
	current->isMazeEnd = true;
	
	return start;
};

