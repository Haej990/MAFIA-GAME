# ENGG1340/COMP2113
_group project_ Mafia game_
groupmates: Kim Da Hyung (3035717406) / Kim Hae Joon (3035602766)

## Rules:
1. 6 computers and one player in a game assigned with different storylines. The choice of becoming a criminal in these 6 people is random.
2. There will be 9 pieces of evidences, and they will be distributed in 9 different places in random.
3. Contents of evidence will be depending on the choice of the criminal.
4. There will be 9 rooms and 9 evidence, and find all the evidences. 
5. Every 3 evidences, chance to pick a criminal is given to a player. If the person choosen is not a criminal, game is over. One can also skip this chance.
6. At the end of the 9 evidences one must choose one person as a criminal. 

## Features and Implementations:
1. Beginning of the game, the player can key in their name and the name will be saved.
2.  Randomly choosen criminal, randomly placing the evidence. There will be 6 different scenarios and each scenario equals to who is getting choosen randomly as a crinaminals. => Generation of random game sets or events and Data structures for storing game status. Not all the scenarios are made, below is the example of a scenario.  
    - Names are not completely made : Chandler: 32 years old, male, the boyfriend of Monica. Rachael: 30 years old, female, the ex-wife of Ross. Monica: 31 years old, the female,   the older sister of Ross, and best friend of Racheal.Joey: 30 years old, male, playboy and loves food.Ross: 32 years old,  male, the ex-husband of Rachael.Phoebe: 31 years old, female, had a rough childhood, but kind and nice. Have a crush on Chandler. 
    - Given 9 rooms: Master bedroom, kitchen, studyroom, hall, playroom, Dinning room, toilet, TV room, and library. 
    - The player can input one of the rooms, and file that is named as that room will open. For example, input: studyroom => ouput: "drawers", "desk", "computer", and "chair". The player can type in any of the options and inspect for the evidence. This will be written in the txt file called Maps. 
    - Assume Chandler was assigned to be a crinminal and also assume that one evidence is found. Input one of the options: desk. Output: a voice recorder was found, the voice recorder is played and there are two voices recorder, one female and one male arguing about their relationships. 
    - After doing more inspection and finding 3 evidence; Please input a name or "skip": . If given name is wrong: Output: "He/she was found to be innocent, please try again next time." If correct name, output: " He/she was found be the killer" "Game over" "input "try agiain" or "exit".This function will be separately stored in a txt file called "Guess".
3. Stoylines of the randomly choosen criminals => Generation of random game sets or events and Data structures for storing game status.
4. Creating new variables, when evidences are picked up (inventories) => Dynamic memory management.
5. Save and exit and loading back => Data structures for storing game status and File input/output.
6. Program codes in multiple files =>
   - Saving and exit, making different txt files and deleting pervious saved txt file.
   - txt file for storylines of all the 6 possible criniminals. 
   - txt file for 9 pieces of evidence of all the 6 possible criminals.
   - Randomly assgining a criminal and the position of the 9 evidences.
   - Inventories of the players will be save and stored in a inventory.txt file.
   - player status (e.g position of the player, movement of a player, and feature for reading evidence). 
   - In text documentation is given in the codes and the codes will be assigned with good naming system. 

