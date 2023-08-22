//Sam Beggs
//M5: Final Capstone Programming Assignment
//12/10/2022
// Final3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#pragma once
#include <iostream>
#include "Maze.h"
#include "Player.h"
#include "GameActor.h"
#include "Cell.h";
//#include "Cell.h"
int main()
{
	cout << "You find your self trapped in a dungeon\n";
	cout << "Navigate the dungen's twisting and turning corridors to freedom\n";
	cout << "Bewhere of  hostile creatures and dead ends\n";

	int mazeWidth = 4;
	int mazeHeight = 4;
	Maze maze(mazeWidth, mazeHeight);
	maze.setMazePath();

	Cell* start = maze.setEndPoints();

	

	Player user(100, start);


	
//try catch is for inputs of invalid types
//inputs with incorrect values will be handled by else statment in movePlayer
//RETRY:
	try {

		user.movePlayer(*start);
	}
	catch (Cell e) {
		cout << "Invalid input: Zero or incorect data type entered";
		//start = e;
		//Player user(100, &start);
		//goto RETRY;
	}
	// ends game if dead
	// ends game if game won
	



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
