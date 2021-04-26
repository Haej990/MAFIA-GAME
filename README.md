# ENGG1340/COMP2113
_group project_ Mafia game_
groupmates: Kim Da Hyung (3035717406) / Kim Hae Joon (3035602766)

## Rules:
1. When the game is run, read the output well and follow it wisely.
3. There are 6 characters and one player. At random, one of the 6 characters will become a criminal, and there will be a storyline adjusted with the chosen character.
4. The objective of the game is to find the criminal by given evidence.
5.  There will be 9 pieces of evidence, and they will be distributed in 9 different rooms at random (e.g. "study", "hall", "lounge", "dining room", "kitchen", "ballroom", "conservatory", "billiard room", "library").
6.  4 of the evidence are traps, so your action can result consequences.
7.  4 of the evidence are valid, and find the key to get the criminal.
8.  The criminal has released a Hound, when it is near by you have to stay quiet.
9.  If not, the bag/inventory will go empty.
10. You can press integer 3 to save and exit the game. 
11. We assume that the player input are valid inputs, except the "quiet" function. 
12. The player only can save once, so choose wisely. 

## Features and Implementations:
1. Generation of Random game sets or events:
   - The starting position of the detective is random. 
   - The distribution of the evidence will be distributed randomly in 9 different rooms.
2. Data structure for storing game status: (probably use class and its data members).
   - The Player:
      - player position.
      - player name.
      - player inventories.
   - The evidence:
      - positions of evidence.
      - found evidence and not found evidence.
      - type of evidence and content of the evidence.
   - The criminal:
      - Randomly chosen character as a criminal.
      - Storyline (which depends on the randomly chosen criminal).
3. Dynamic memory management:
   - The bag is a string vector, used push_back() function to append the collected evidence.     
   - Use of <map> to create a list to code the movement. 
4. File I/O:
   - There is going to be a text file that contains a list of characters, which will be read when randomly choosing a criminal (e.g [character_list].txt file).
   - Map diagram is saved as a text file. 
   - If a player exit, the bag/inventory of the player, the position of the player,life count, and position of 9 evidence will be stored in a text file.
   - If player want to continue the saved game, player have to input the username that was keyin before. This will load the previous game.  
5. Program codes in multiple files:
   - The whole program of the game will be separated into various files, such as (.cpp and .h files).
6. Proper indentation and naming styles, and In-code documentation:
   - This will be shown coding and the project itself. 

## To Run
We have put all the files needed (.cpp .h .txt and makefiles) in testfiles. 
Use make at the command line to compile ./playgame to run

