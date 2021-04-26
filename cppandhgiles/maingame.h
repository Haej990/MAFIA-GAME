#ifndef MAINGAME_H
#define MAINGAME_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "inventory.h"
#include "move.h"
using namespace std;

class Maingame{
public:

  string pname;

  void endgame();
  
  string getname() const;

  void printStatus(Map& gameMap, Inventory& bag);

  void printRules(string &pname);

  void setBoard(Map& gameMap);

  void startgame(Map& gameMap, Inventory& bag, Move& movement, string &pname);
  
  void movement(string c[9], int command);

  void savegame(Map& gameMap, Inventory& bag, Move& movement, string &pname);
  
  bool loadgame(Map& gameMap, Inventory& bag, Move& movement);
};

#endif
