#include <iostream>
#include <string>
#include <map>
#include "map.h"
#include "move.h"
#include "maingame.h"
#include "inventory.h"

using namespace std;

Move::Move(){
  // For the movement/excute command, it requires rooms to be allocated with integers.
  location = 
  {
    {"study", 0}, 
    {"hall", 1}, 
    {"library", 2},
    {"billiard room", 2},
    {"lounge", 3},
    {"kitchen", 4},
    {"conservatory", 5},
    {"dining room", 6},
    {"ballroom", 7}
  };
  
  string rooms[9] = {"study", "hall", "lounge", "dining room", "kitchen", "ballroom", "conservatory", "billiard room", "library"};
}
//print out diffent option for movement according to the location of the room 
void Move::printByLocation(string room){
  cout << "location[room]: " << room << endl;

  if(location[room] == 0 ){
    cout<< "Press number 1 (down) or 2 (right) or 3 (save and exit) " << endl;
  }
  else if(location[room] == 1 ){
    cout<< "Press number 1 (left) or 2 (right) or 3 (save and exit) " << endl;
  }
  else if(location[room] == 2 ){
    cout<< "Press number 1 (down) or 2 (up) or 3 (save and exit)" << endl;
  }
  else if(location[room] == 3 ){
    cout<< "Press number 1 (left) or 2 (down) or 3 (save and exit) " << endl;
  }
  else if(location[room] == 4 ){
    cout<< "Press number 1 (up) or 2 (left) or 3 (save and exit)" << endl;
  }
  else if(location[room] == 5 ){
    cout<< "Press number 1 (right) or 2 (up) or 3 (save and exit)" << endl;
  }
  else if(location[room] == 6 ){
    cout<< "Press number 1 (up) or 2 (down) or 3 (save and exit)" << endl;
  }
  else if(location[room] == 7 ){
    cout<< "Press number 1 (right) or 2 (left) or 3 (save and exit)" << endl;
  }
  else{
    cout << " Invalid input " << endl;
  }
}

//if press 1, the player position goes to anticlockwise, of press 2, the player goes to clockwise
void Move::executeCommand(int command, Map & gamemap){
  string currentRoom = gamemap.get_player_position(); // string room name
  int pos = gamemap.get_position_int(currentRoom); // room's position in integer according to its vector position

  //if player's input is 1, position moves to the anticlockwise adjacent room
  if(command == 1){

    if (pos != 0){
      pos--; //subtract integer position by one
      gamemap.callAtFunctions(pos);
    }else{
      pos = 8;
      gamemap.callAtFunctions(pos);
    }
  //if player's input is 2, position moves to the clockwise adjacent room
  }else if(command == 2){
    if (pos != 8){
      pos++; //plus one to integer position 
      gamemap.callAtFunctions(pos);
    }else{
      pos = 0;
    gamemap.callAtFunctions(pos);
    } 
  }else{
    cout << "Not valid command" << endl; 
  }
}

// A fcuntion to loop a movement commands.
void Move::movementloop(Map& gameMap, Inventory& bag){  
  int command;
  bool youWin = false;

  while (!youWin){ //check if the picked up item is a trap or not.

    printByLocation(gameMap.get_player_position());
    cin >> command;
    if (command!=1 && command!=2 && command !=3){
      cout << "Not valid command" << endl; 
    } else if ( command ==1 || command == 2){
      executeCommand(command, gameMap);
      gameMap.giveoutboard();
      gameMap.printKey(); 
    } else if (command == 3){
      break;
    }
    // quiet function 
    cout << endl;
    gameMap.quiet(bag);
    if (gameMap.lifeCount <= 0) { // see if life count smaller or equal to zero. 
      cout << "You got caught by the criminal and disappeared with no trace. " << endl;
      cout << "...Game Over...\n" << endl;
      break; // game is over if life is zero. 
    }
    cout << endl;
    youWin = bag.checkItem(gameMap.get_player_position(), gameMap.lifeCount);

    if (gameMap.lifeCount <= 0) { 
      cout << " You got caught by the criminal and disappeared with no trace. " << endl;
      cout << "...Game Over...\n" << endl;
      break;
    }
  }
}

