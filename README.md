# labyrinth
Text based adventure game
**Labyrinth Game Overview**

Labyrinth is a sophisticated text-based dungeon exploration game. In this interactive environment, participants navigate through a semi-procedurally generated universe, collecting supplies and confronting various challenges.

**Combat Mechanics**

The combat system in Labyrinth is structured around two primary design elements: one that governs the actions of enemy AI and another that determines the actions available to the player.

1. **Initiating Combat:** A player can either avoid combat or make the first move based on two conditions:
   a. The player's stealth attribute surpasses the enemy's perception attribute.
   b. The player's speed attribute exceeds that of the enemy.
   
   If neither of these conditions are met, the player is compelled to engage in combat and will act after the enemy.
   
2. **Turn-based Actions:** During their turn, players can choose from a variety of actions, including attacking or healing. Every action depletes time points. Once all time points are exhausted, the turn concludes. Combat continues with the player and enemy alternating turns until one party's health points are completely depleted.

**Exception Handling Mechanism**

The primary input method is through integers, each corresponding to a specific option in a menu. Potential errors arise when:
   a. A user inputs an integer not present in the menu.
   b. A user provides non-integer data.

To manage these exceptions:
- All non-integer inputs are processed as zero.
- The menu is designed to exclude the option of zero.
- If the user's input doesn't match any menu options, an exception is invoked via an "else" clause. The user will then be prompted to provide a valid input.

**Game Map and Data Structure**

Within Labyrinth, players traverse a meticulously designed game map consisting of a grid of cells. Each of these cells represents a distinct area and is an instance of a custom class. This class has characteristics akin to a double-linked list, but with a unique twist: every node has four distinct links, allowing movement north, east, south, or west.

**Maze Generation Algorithm:** 
Initially, all cell links are in a locked state. The algorithm strategically generates paths by unlocking certain links, ensuring every cell becomes accessible to the player. The final product consists of a mix of unlocked pathways (open spaces) and locked pathways (walls).
