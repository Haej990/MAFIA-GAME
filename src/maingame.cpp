// CPP file that has functions for the game to run, which are combination of other functions from other cpp files. 


#include <iostream>
#include <string>
#include "maingame.h"
#include "maphj.h"
#include "distribute.h"
#include "movehj.h"
#include "inventory.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

string Maingame::getname() const { // a function that gets user name. 
	string pname;
  cout << "Please key in your one word name: ";
	cin >> pname;
	return pname;
}

void Maingame::endgame() {
  cout << "### Game ended ###" << endl;
  // fucntion to print out end game statment
}

void Maingame::printRules(string &pname) { // Print rules out to the users. 

  cout << "######### Message Received #########" << endl;
  cout << "Hello " << pname << "." << endl;
  cout << "You are here to solve a crime and you, " << pname << ", is going to be our detective." << endl;
  cout << "This is the message from your boss." << endl;
  
  ifstream fin; // rules were long, so used txt file. 
  fin.open("rules.txt");
  string lines;
  while (getline(fin, lines)) {
    cout << lines << endl;
  }
  cout << "Wish you the best." << pname << endl;
  cout << "##################################\n" << endl;
}


//Function used when first starting the game, where starting point is set in random. 
void Maingame::setBoard(Map& gameMap){ 
  char cont; // continue variable
  cout << "Press \"c\" to continue." << endl;
  cin >> cont;

  if (cont == 'c'){
    srand(time(NULL));
    int j = rand()%9; // randomly choose the index to choose from vector called rooms which is a starting point.
    string initialpos = gameMap.rooms[j];
    if (initialpos == "study"){
      gameMap.atstudy();
    } else if (initialpos =="hall"){
      gameMap.athall();
    } else if(initialpos=="lounge"){
      gameMap.atlounge();
    } else if (initialpos =="dining room"){
      gameMap.atdiningroom();
    }else if (initialpos == "kitchen"){
      gameMap.atkitchen();
    } else if (initialpos == "ballroom"){
      gameMap.atballroom();
    } else if (initialpos == "conservatory"){
      gameMap.atconservatory();
    } else if (initialpos == "billiard room"){
      gameMap.atbilliardroom();
    } else{
      gameMap.atlibrary();
    }
    gameMap.giveoutboard(); // printing out the game board.
    gameMap.printKey(); // Printing movement keys
  }
}

// function that initiate the whole game. 
void Maingame::startgame(Map& gameMap, Inventory& bag, Move& movement, string &pname) {
	string status;
	cout << "### Enter \"y\" to start or \"n\" to exit ###" << endl;
	cin >> status;

	if (status == "y") {
    string status1;
    cout << endl;
    cout << "Do you want to start from saved point (y/n)? "; // to ask whether to continue the game as saved before. 
    cin >> status1;
    cout <<endl;
    if (status1 == "y"){ // loadgame, when there is no file as such name, create new game.
      bool check = loadgame(gameMap, bag, movement);
      if(check == true){ // if there is a file name as input, continue loading and start game. 
        gameMap.giveoutboard();
        gameMap.printKey();
        movement.movementloop(gameMap, bag);
        savegame(gameMap, bag, movement, pname);// save the game when save and exit
      } else{ // if there is no file in name as input, start new game. 
        cout << "Therefore, creating new game" << endl;
        pname = getname();
        printRules(pname);
        setBoard(gameMap); //randomize the starting position.
        bag.shuffleItems(); //randomize the distribution 
        movement.movementloop(gameMap, bag);
        savegame(gameMap, bag, movement, pname); //save game when save and exit
      }
    } else if(status1 =="n"){ //if player want to play new game
      pname = getname();
      printRules(pname);
      setBoard(gameMap); //randomizing the starting position.
      bag.shuffleItems(); // randomize the distribution. 
      movement.movementloop(gameMap, bag);
      savegame(gameMap, bag, movement, pname);
    }
	} else if (status == "n") { //exit game
		endgame();
	} else {
		cout << "\n### Please key in as mentioned in the message ###\n" << endl;
		startgame(gameMap, bag, movement, pname); //restarting the game.
	}
}

// function to save the player status of the game in txt file. 
void Maingame::savegame(Map &gameMap, Inventory &Bag, Move &movement, string &pname){
  ofstream fout;
  string txtname = pname + ".txt"; // make into a [filename].txt 
  fout.open(txtname);
  string lines;
  fout << "**BAGS**" << endl; // from this line to next elements needed for the game. 
  for ( int i= 0; i < Bag.bag.size(); i++){
    fout<< Bag.bag[i] << endl;
  }
  fout << "**DISTRIBUTION**" << endl; //indication for next item.
  for ( int j =0 ; j < Bag.items.size();j++){
    fout << Bag.items[j] <<endl;
  }
  fout << "**LIFE**" << endl; // indication for next item
  fout << gameMap.lifeCount <<endl;
  string current_p_position = gameMap.get_player_position();
  fout << "**CURRENTPOSITION**" << endl; //indication for next item
  fout << current_p_position << endl;
  fout.close();
}

// function to load back the game as previous saved and exit. 
bool Maingame::loadgame(Map& gameMap, Inventory& Bag, Move& movement){
  ifstream fin;
  string pname;
  string lines, previousfilename;
  cout << "Please key in last user name: "; // see if there is saved game with input username
  cin >> previousfilename;
  previousfilename = previousfilename + ".txt";
  fin.open(previousfilename);
  if(fin.fail()){
    cout<<"There is no file saved in that name" <<endl;
    cout <<endl;
    return false;
  }else {
    while (getline(fin, lines)){
      if (lines == "**BAGS**"){
        while (getline(fin, lines)){
          if ( lines == "**DISTRIBUTION**"){
            break;
          } else {
            Bag.bag.push_back(lines); // no known size for this vector, so used push_back.
          }
        }        
      } 
      if (lines == "**DISTRIBUTION**"){
        int j =0;
        while (getline(fin, lines)){
          if ( lines ==  "**LIFE**"){
            break;
          } else {
            Bag.items[j] = lines; // in the order of the rooms.
            j++;
          }
        }
      } 
      if (lines == "**LIFE**"){
        while (getline(fin,lines)){
          if ( lines == "**CURRENTPOSITION**" ){
            break;
          } else {
            gameMap.lifeCount = stoi(lines);
          }
        }
      } 
      if(lines == "**CURRENTPOSITION**"){
        getline(fin,lines);
        gameMap.set_player_position(lines);
      }
    }
  }
  fin.close();
  return true;
}