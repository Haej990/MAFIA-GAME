#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>
#include <map>
#include "map.h"
#include "inventory.h"
using namespace std; 

class Move{
public:
  map <string, int> location;

  string rooms[9];

  Move();

  void printByLocation(string room);

  void executeCommand(int command, Map& gamemap);

  void movementloop(Map& gameMap, Inventory& bag);

  int startposition();
};

#endif

