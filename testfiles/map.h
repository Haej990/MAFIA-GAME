#ifndef MAP
#define MAP 

#include <string> 
#include <iostream>
#include <vector>
#include "inventory.h"

using namespace std;

class Map { 

private:
  string player_position;
  int    player_location;

public:
  string gameboard[28][60];
  void resetpos();
  
  Map();

  void atstudy();
  void athall();
  void atlounge();
  void atlibrary();
  void atbilliardroom();
  void atconservatory();
  void atballroom();
  void atkitchen();
  void atdiningroom();

  void giveoutboard();
  void printKey() const;
  
  int getIndex(vector<string> vector, string room);

  vector<string> rooms;

  int lifeCount = 3;

  void quiet(Inventory& bag);

  string get_player_position();
  
  int get_position_int(string room){
    // will return position of room 0~8 according to vector<> rooms
    return getIndex(rooms, room);
  }

  void set_player_position(string &position);

  void callAtFunctions(int pos){
    switch(pos) {
      case 0:
        atstudy();
        break;
      case 1:
        athall();
        break;
      case 2:
        atlounge();
        break;
      case 3:
        atdiningroom();
        break;
      case 4:
        atkitchen();
        break;
      case 5:
        atballroom();
        break;
      case 6:
        atconservatory();
        break;
      case 7:
        atbilliardroom();
        break;
      case 8:
        atlibrary();
        break;
    }
  }


};

#endif
