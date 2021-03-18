# ENGG1340/COMP2113
_group project_ Mafia game_
groupmates: Kim Da Hyung (3035717406) / Kim Hae Joon (3035602766)

## Rules:
1. Input the name of the player and press enter. The game will begin. If the player wants to exit, press 1.
3. There are 6 characters and one player. At random, one of the 6 characters will become a criminal, and there will be a storyline adjusted with the chosen character.
4. The object of the game is to find the criminal by given evidence.
5.  There will be 9 pieces of evidence, and they will be distributed in 9 different rooms at random (e.g. Master bedroom, kitchen, study room, hall, playroom, Dinning room, toilet, TV room, and library).
6.  Contents of evidence will be depending on the choice of the criminal.
7.  There will be 9 rooms and 9 pieces of evidence, and find all the evidence. 
8.  For Every 3 pieces of evidence, the chance to guess a criminal is given to a player. If the person has chosen is not a criminal, the game is over. One can also skip this chance.
9.   At the end of the 9 pieces of evidence one must choose one person as a criminal. 
10. General outline of the game: Not all the scenarios are made but, below is an example of a scenario.  
    - Names are not completely made : Chandler: 32 years old, male, the boyfriend of Monica. Rachael: 30 years old, female, the ex-wife of Ross. Monica: 31 years old, the female, the older sister of Ross, and best friend of Racheal. Joey: 30 years old, male, playboy and loves food. Ross: 32 years old,  male, the ex-husband of Rachael. Phoebe: 31 years old, female, had a rough childhood, but kind and nice. Have a crush on Chandler. 
    - Given 9 rooms: Master bedroom, kitchen, study room, hall, playroom, Dinning room, toilet, TV room, and library. 
    - The player can input one of the rooms, the detail of the room will be called. For example, input: study room => output: "drawers", "desk", "computer", and "chair". The player can type in any of the options and inspect for the evidence. 
    - Assume Chandler was assigned to be a criminal and also assume that one piece of evidence is found. Input one of the options: desk. Output: a voice recorder was found, the voice recorder is played and there are two voices recorded, one female and one male arguing about their relationships. 
    - After doing more inspection and finding 3 pieces of evidence; “Please input a name or "skip":”. If the given name is wrong: Output: "He/she was found to be innocent, please try again next time." If the correct name, output: " He/she was found to be the killer" "Game over" "input "try again" or "exit". 
    - And these will be repeated.

## Features and Implementations:
1. Generation of Random game sets or events:
   - The choice of the criminal will be randomly generated.
   - The distribution of the evidence will be distributed randomly in 9 different rooms.
2. Data structure for storing game status:
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
   - When collecting evidence, the pieces of evidence will be stored in form of a string array (using new and delete operators).
4. File input/output:
   - All 6 scenarios will be saved as different text files, such as [character_name].txt (depending on who becomes a criminal), which will be read to randomly distribute the 9 pieces of evidence.
   - There is going to be a text file that contains a list of characters, which will be read when randomly choosing a criminal (e.g [character_list].txt file).
   - There will be a list environment will be in a text file (e.g. [room].txt), which will be read whenever the players move from one room to another and when searching for evidence. (e.g. desk, computer and etc). 
   - Whenever a player wants to exit, the storyline, the position of the player, and position of 9 evidence will be stored in a file. 
5. Program codes in multiple files:
   - The whole program of the game will be separated into various files, such as (.cpp and .h files).
6. Proper indentation and naming styles, and In-code documentation:
   - This will be shown coding and the project itself. 
