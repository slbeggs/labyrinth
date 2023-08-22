#pragma once
#include "Player.h"
;
using namespace std;
//Transverse player across maze;
// recursive -Calls movePlayer() till maze end has been found or player  dies
// return Cells visted by player
Player::Player(int hp, Cell* actorLoc) : GameActor(hp, actorLoc) {

    isAlive = true;

}
Player::Player() {
    isAlive = true;

}

Cell Player::movePlayer(Cell current) {
    actorLoc = &current;
    // is player is in the same location as an enemy?
    if (current.hasEnemy) {
        // Enemy near player
        Enemy* enemy = new Enemy(25, actorLoc);
        //Starts combat with enemy
        combat(enemy);
        // destructs dead ememy
         delete enemy;
    }
    // has player died?
    if (!isAlive) {
        cout << " player died! game over";
        cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;

        return current;
    }  // has player found end of maze ?
    else if (current.isMazeEnd) {
        cout << "congratulations ! Youve escaped the dungeon!"<< endl;
        cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
        return current;
    }
    current.printCell();
    // select direction to travel
    int direction = 0;
    cin >> direction;
    // go north
    if (direction == 1) {
        if (current.hasPathUp) {
            movePlayer((*current.upCell));
            cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
            return current;
            //actorLoc = actorLoc->upCell;
        }
        else {
          cout <<  "Path blocked" << endl;
          movePlayer(current);
          cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
          return current;
          
        }
    }
    // go east
    else if(direction == 2) {
        if (current.hasPathRight) {
            movePlayer((*current.rightCell));
            cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
            return current;
           //actorLoc = actorLoc->rightCell;
        }
        else {
           cout << "Path blocked" << endl;
           movePlayer(current);
           cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
           return current;
        }
    }
    // go south
    else if (direction == 3) {
        if (current.hasPathDown) {
            movePlayer((*current.downCell));
            cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
            return current;
            //actorLoc = actorLoc->downCell;
        }
        else {
           cout << "Path blocked"<< endl;
           movePlayer(current);
           cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
           return current;
        }
    }
    // go west
    else if (direction == 4) {
        if (current.hasPathLeft) {
            movePlayer((*current.leftCell));
            cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
            return current;
           /// actorLoc = actorLoc->leftCell;
        }
        else {
            cout << "Path blocked"<< endl;
            movePlayer(current);
            //cout << "Loc:(" << current.xLoc << "," << current.yLoc << ") " << endl;
            return current;
        }
    }
    // invalid input : zero or incorret data type quits program
    else if (direction == 0) {
       
       
        throw current;
    }
    else {
        cout << "Invaild input: int out of range";
        movePlayer(current);
       
        return current;
    }
    
  
    
    
}
int Player::attack(GameActor* target) {
    // Using current time as seed for random generator
    srand(time(0));     
    // generating an attack value from 5 to 10
    int attack = (rand() % 6) + 5;    
    if ((this->bag).hasSword) {
        weaponModifier = 3;
    }
    target->hp -= (attack * weaponModifier);
    
    return attack * weaponModifier;
}

// Combat mode of game
void Player:: combat(GameActor* enemy) {
    cout << endl << "An enemy is approching\n";
    cout << endl << "combat has began\n";
    // Combat continues till either player or enemy dies 
    while (hp > 0 && enemy->hp > 0)  
    {
        cout << "Player's HP: " << hp << endl;
        cout << "Enemy's HP: " << enemy->hp << endl;

        // Explore Action
        srand(time(0));
        int dice = (rand() % 4) + 1;      // generating a random number from 1 to 4

        if (dice == 1) {
            bag.hasPotion = true;
            cout << "You got a potion.\n";
        }
        else if (dice >= 3) {
            bag.hasSword == true;
            cout << "You got a sword.\n";
        }

        // Player's turn
        // Assuming the player always attacks first
        int input;
        bool playerTurn = true;
        cout << "enter 1: Heal\ enter 2: Weapon attack\n";

        while (playerTurn) {
            cin >> input;
            int hpRecov;
            switch (input) {
            case 1:
                hpRecov = heal();
                if (hpRecov < 0)
                    cout << "You don't have potion to heal.\n";
                else
                    cout << "HP increased by " << hpRecov << endl;
                hpRecov = false;
                break;
            case 2:
                attack(enemy);
                playerTurn = false;
                break;
            // invalid input : zero or incorret data type quits program
            case 0:
                throw(Cell());
            default:
                cout << "Invalid input: int out of range\n";
            }
        }
        // Enemy's turn
        enemy->attack(this);
    }
    //player death
    if (hp < 0) {
        isAlive = false;

    }
    else {
        cout << "Enemy Defeated\n";
        actorLoc->hasEnemy = false;
       
    }

}