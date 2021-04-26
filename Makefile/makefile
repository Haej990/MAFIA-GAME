playgame: game.o inventory.o map.o move.o maingame.o
	g++ game.o inventory.o map.o move.o maingame.o -o playgame

game.o: game.cpp 
	g++ -c game.cpp

inventory.o: inventory.cpp inventory.h
	g++ -c inventory.cpp

map.o: map.cpp map.h
	g++ -c map.cpp

move.o: move.cpp move.h map.h maingame.h inventory.h
	g++ -c move.cpp

maingame.o: maingame.cpp maingame.h map.h move.h inventory.h
	g++ -c maingame.cpp

clean:
	rm *.o playgame 
