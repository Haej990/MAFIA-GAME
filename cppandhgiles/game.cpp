#include <iostream>
#include <string>
#include "maingame.h"
#include "map.h"
#include "move.h"
#include "inventory.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  // Start Game
  Map gameMap;
  Maingame mainGame;
  Inventory bag;
  Move movement;
  string name;
  cout << "########## Welcome to DETECTIVE GAME! ###########" << endl;
  cout << endl;
  mainGame.startgame(gameMap, bag, movement, name);// function to run the game. 
  cout << "~~ Thank you for playing ~~" << endl;
}
