#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class Inventory{
public:
  Inventory();

  vector <string> items;

  vector <string> traps;

  vector <string> bag;

  vector <string> rooms;
  

  void resetInventory();

  bool addInventory(int index);

  bool checkItem(string room, int& lifeCount);

  void shuffleItems();

  void printInventory();

  void printItems();

  bool checkbagsize();
  
};

#endif