# ENGG1340/COMP2113
_group project_ Mafia game_
groupmates: Kim Da Hyung (3035717406) / Kim Hae Joon (3035602766)

## Rules:
1. 6 computers and one player in a game assigned with different storylines. The choice of becoming a criminal in these 6 people is random.
2. There will be 9 pieces of evidence, and they will be distributed in 9 different places at random.
3. Contents of evidence will be depending on the choice of the criminal.
4. There will be 9 rooms and 9 pieces of evidence, and find all the evidence. 
5. For Every 3 pieces of evidence, the chance to pick a criminal is given to a player. If the person has chosen is not a criminal, the game is over. One can also skip this chance.
6. At the end of the 9 pieces of evidence one must choose one person as a criminal. 

## Features and Implementations:
1. Beginning of the game, the player can key in their name and the name will be saved.
2.  Randomly chosen criminal, randomly placing the evidence. There will be 6 different scenarios and each scenario equals who are getting chosen randomly as a criminal. => Generation of random game sets or events and Data structures for storing game status.
3. Storylines of the randomly chosen criminals => Generation of random game sets or events and Data structures for storing game status.
4. Creating new variables, when evidence is picked up (inventories) => Dynamic memory management.
5. Save and exit and loading back => Data structures for storing game status and File input/output.
6. Program codes in multiple files =>
   - Saving and exit, making different txt files, and deleting previously saved text files.
   - txt file for storylines of all the 6 possible criminals. 
   - txt file for 9 pieces of evidence of all the 6 possible criminals.
   - Randomly assigning a criminal and the position of the 9 pieces of evidence.
   - Inventories of the players will be saved and stored in an inventory.txt file.
   - player status will be stored as a game_status.txt file (e.g position of the player, movement of a player, and feature for reading evidence). 
   - In-text documentation is given in the codes and the codes will be assigned with a good naming system. 
7. Not all the scenarios are made but, below is an example of a scenario.  
    - Names are not completely made : Chandler: 32 years old, male, the boyfriend of Monica. Rachael: 30 years old, female, the ex-wife of Ross. Monica: 31 years old, the female,   the older sister of Ross, and best friend of Racheal.Joey: 30 years old, male, playboy and loves food.Ross: 32 years old,  male, the ex-husband of Rachael. Phoebe: 31 years old, female, had a rough childhood, but kind and nice. Have a crush on Chandler. 
    - Given 9 rooms: Master bedroom, kitchen, study room, hall, playroom, Dinning room, toilet, TV room, and library. 
    - The player can input one of the rooms, the detail of the room will be called. For example, input: study room => output: "drawers", "desk", "computer", and "chair". The player can type in any of the options and inspect for the evidence. This will be written in the txt file called "[name of the room].txt file". 
    - Assume Chandler was assigned to be a criminal and also assume that one piece of evidence is found. Input one of the options: desk. Output: a voice recorder was found, the voice recorder is played and there are two voices recorded, one female and one male arguing about their relationships. 
    - After doing more inspection and finding 3 pieces of evidence; “Please input a name or "skip":”. If the given name is wrong: Output: "He/she was found to be innocent, please try again next time." If the correct name, output: " He/she was found to be the killer" "Game over" "input "try again" or "exit".This function will be separately stored in a text file called "Guess". 
