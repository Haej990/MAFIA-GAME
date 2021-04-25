//functions related to inventory and evidence distribution. 

#include <iostream>
#include <string>
#include "inventory.h"
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
using namespace std;

//Save Items, traps and rooms in vector STL  
Inventory::Inventory(){ 
  items = {"letter", "knife", "recorder", "rope", "key", "glass of wine", "cigarette", "guitar", "TV"}; // the same index as the rooms is evidence in that room.

  traps = {"glass of wine", "cigarette", "guitar", "TV"};

  rooms = {"study", "hall", "lounge", "dining room", "kitchen", "ballroom", "conservatory", "billiard room", "library"};

  bag = {}; //set empty bag vector before collecting items
}

void Inventory::resetInventory(){
  bag.clear(); //pops of all the items in bag vector
  items = {"letter", "knife", "recorder", "rope", "key", "glass of wine", "cigarette", "guitar", "TV"};
  shuffleItems();
}
//Randomly shuffle the contents of vector
void Inventory::shuffleItems(){
  srand(time(NULL));

  unsigned int j = rand()%9;

  auto rng = default_random_engine {j};
  shuffle(begin(items), end(items), rng);
}
//list out items in current bag
void Inventory::printInventory(){
  cout << "###### This is your inventory ######" << endl;
  for (int i = 0; i < bag.size(); i++) {
    cout << "|" << bag[i] << "|"; 
  }
  cout << endl;
}

void Inventory::printItems(){
  cout << "###### Current location of Items ######" << endl;
  for (int i = 0; i < items.size(); i++) {
    cout << rooms[i] << ": " << items[i] << "\n"; 
  }
}

//bool function that adding items to bag
bool Inventory::addInventory(int index){
  // items in items vector changed to "-" whenever they are collected to avoid overlap
  if (items[index] == "-") {
    cout << "This room was already investigated. This room is empty. " << endl;
  }
  else {
    string yesNo;
    cout << "You found [" << items[index] << "]." << endl;
    cout << "This might help to solve the case! Do you want to pick it up? (y/n): ";
	  cin >> yesNo;
      
    if (yesNo == "y") {
      bag.push_back(items[index]);
      items[index] = "-";// to set the room as empty.
  

      if (bag.size() >= 5) { // check if all the evidence is collected 
        string catch_input;
        cout << "##################################################\n";
        cout << " Wow! You collected all the clues. You also seem to have a key with you!"<< endl;
        cout << "Use this key to find the criminal hiding in a locked room. Key in \"catch\" to proceed. " << endl;
        cout << "#################################################\n";
        cin >> catch_input; 
        if ( catch_input == "catch"){
          cout << "##### -------- YOU GOT THE CRIMINAL, AND FOUND GUILTY! -------- #####" << endl;
          cout << "######--The criminal was sentenced a life time in prison--######" <<endl; 
          cout << "#####-- You have become a new Sherlock Holmes --#####"<< endl;
          return true;
      
        }
      }
    }
    printInventory();
  }
  return false;
}


bool Inventory::checkItem(string room, int& lifeCount){
  bool hasWon = false;

  // find item in the room
  auto it = find(rooms.begin(), rooms.end(), room);
  int index; // index of item
  if (it != rooms.end())
    index = it-rooms.begin();
  else
    cout << "ERROR (inventory.cpp_83)" << endl;

  // check whether the item is a trap or not
  auto trapIt = find(traps.begin(), traps.end(), items[index]);
  if (trapIt != traps.end()) {
    string yesNo;   
    cout << "You found [" << items[index] << "]." << endl;

    if(items[index]=="glass of wine"){ // different outcomes for different traps. 
      cout << "You feel little thirsty. Do you want to drink it? Press (y/n): ";
      cin >> yesNo;
      if (yesNo == "y") {
        resetInventory();
        cout << "*********************************************************\n";
        cout << "The eyes started to shut and, the heartbeat started to slow down, there must have been poison in it. You have lost all your inventory..." << endl;
        lifeCount--; // it is trap and reduce life. 

        if (lifeCount>0) {
          cout << "You have [" << lifeCount << "] chances left !" << endl;
         
        }
      }
    }
    if(items[index]=="cigarette"){
      cout << "*********************************************************\n";
      cout << "All detectives smoke cigarette when solving a case. Do you want to smoke it? Press (y/n): ";
      cin >> yesNo;
      if (yesNo == "y") {
        resetInventory()
        ;
        cout << "Smoke started to accumulate until it is very visible and got caught by the criminal." << endl;
        lifeCount--;

        if (lifeCount>0) {
          cout << " You ran away with everything behind..." << endl;
          cout << "You have [" << lifeCount << "] chances left !" << endl;
        }
      }
    }
    if(items[index]=="guitar"){
      cout << "A Little Fun Never Hurt Anyone! Do you want to play the guitar? Press (y/n): ";
      cin >> yesNo;
      if (yesNo == "y") {
        resetInventory();
        cout << "*********************************************************\n";
        cout << "The noise was bigger than expected, you got caught by the criminal." << endl;
        lifeCount--;

        if (lifeCount>0) {
          cout << " You ran away with everything behind..." << endl;
          cout << "You have [" << lifeCount << "] chances left !" << endl;
        }
      }
    }
    if(items[index]=="TV"){
      cout << "You might will find something on the News. Do you want to turn on the TV? Press (y/n): ";
      cin >> yesNo;
      if (yesNo == "y") {
        resetInventory();
        cout << "*********************************************************\n";
        cout << "The TV sound was on maximum, it must have been a trap by a criminal." << endl;
        lifeCount--;

        if (lifeCount>0) {
          cout << "You ran away with everything behind..." << endl;
          cout << "Your inventory is empty." << endl;
          cout << "You have [" << lifeCount << "] chances left !" << endl;
        }
      }
    }
  }
  else
      hasWon = addInventory(index);
  
  return hasWon;
}

