#include <iostream>
#include <string>
#include "map.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
// Buidling and functions related to map of the game. 


Map::Map(){ //contructor to intialize the data. 
  int p=0;
  ifstream fin;
  fin.open("map.txt");
  string lines;
  //fill in 2-D array of the board row by row
  while (getline(fin, lines)){ // calling txt file to 2-D array. 
    for (int j=0; j<60; j++){
      gameboard[p][j] = lines[j];
    }
    p+=1;
  }
  fin.close();
  //Set vector STL of the room for reference in many functions.
  rooms = {"study", "hall", "lounge", "dining room", "kitchen", "ballroom", "conservatory", "billiard room", "library"};
}

void Map::set_player_position(string &position){ // to load the location of the player when loading the saved game. 
  player_position = position;
  if (player_position == "study"){
    atstudy();
  } else if (player_position =="hall"){
    athall();
  } else if(player_position=="lounge"){
    atlounge();
  } else if (player_position =="dining room"){
    atdiningroom();
  }else if (player_position == "kitchen"){
    atkitchen();
  } else if (player_position == "ballroom"){
    atballroom();
  } else if (player_position == "conservatory"){
    atconservatory();
  } else if (player_position == "billiard room"){
    atbilliardroom();
  } else{
    atlibrary();
  }
}

string Map::get_player_position(){
  return player_position; //return player's room 
}
//replace * with space string whenever player's position reset
void Map::resetpos(){
  for ( int i = 0; i < 28;i++){
    for ( int k = 0; k < 60; k++){
      if(gameboard[i][k] == "*"){
        gameboard[i][k] = " ";
      }
    }
  }
}

//prints out the board
void Map::giveoutboard(){
  for ( int row = 0; row < 28; row++){
    for ( int col =0; col < 60; col++){
      cout << gameboard[row][col];
    }
    cout << endl;
  }
}

// Following 9 functions are printing * where player is currently at
void Map::atstudy(){
  resetpos(); // call resetpos function that delete "*" printed before 
  gameboard[1][7] = "*"; //fill up with "*" into studyroom position on 2-D arrayed gameboard
  player_position="study"; // update player_position to the current location
}

void Map::athall(){
  resetpos();
  gameboard[2][30] = "*";
  player_position="hall";
}

void Map::atlounge(){
  resetpos();
  gameboard[1][50] = "*";
  player_position="lounge";
}

void Map::atlibrary(){
  resetpos();
  gameboard[9][7] = "*";
  player_position="library";
}

void Map::atbilliardroom(){
  resetpos();
  gameboard[15][7] = "*";
  player_position="billiard room";
}

void Map::atconservatory(){
  resetpos();
  gameboard[24][7] = "*";
  player_position="conservatory";
}

void Map::atballroom(){
  resetpos();
  gameboard[23][30] = "*";
  player_position="ballroom";
}

void Map::atkitchen(){
  resetpos();
  gameboard[23][50] = "*";
  player_position="kitchen";
}

void Map::atdiningroom(){
  resetpos();
  gameboard[14][50] = "*";
  player_position="dining room";
}

// displays the key for the board 
void Map::printKey() const {
	std::cout << "\t\t\t\tKEY: * YOU ARE HERE" << std::endl;
}

int Map::getIndex(vector<string> vector, string room)
{
  auto it = find(vector.begin(), vector.end(), room); 
  // If element was found
  if (it != vector.end())
  {
    int index = it - vector.begin();
     return index;
  }
  else {
    return -1;
  }
}
// one of the function, where have to type in quiet to stay quiet. 
void Map::quiet(Inventory& bag) {
  srand(time(NULL));
	double prob = ((double)rand() / RAND_MAX); //setting probaility
	if (prob < 0.3) { // getting the hound nearby when probability is lower than 0.3.
		cout << "The hound is nearby, stay quiet!" << endl;
		string keyin;
		cin >> keyin;

		if (keyin == "quiet" || keyin == "Quiet") {
			cout << "Hound has went away..." << endl;
		} else if (lifeCount>0 && (keyin != "quiet"||keyin !="Quiet")){
      bag.resetInventory(); // reset inventory when wrong spelling. 
      cout << "########################################################" << endl;
			cout << "You got caught! You have lost all your inventory..." << endl;
      lifeCount--; // reduce life count.  

      if (lifeCount>0) {
        cout << "You have [" << lifeCount << "] chances left !" << endl;
        cout << "########################################################" << endl;
      }
    }
	}
}

