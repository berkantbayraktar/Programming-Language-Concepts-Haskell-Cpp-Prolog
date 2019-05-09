LDFLAGS=-std=c++11

testPlayer: ;  g++ -g $(LDFLAGS) Archer.cpp Board.cpp Fighter.cpp Game.cpp InputParser.cpp Player.cpp Priest.cpp Scout.cpp Tank.cpp testPlayer.cpp -o testPlayer
testBoard: ; g++ -g $(LDFLAGS) Archer.cpp Board.cpp Fighter.cpp Game.cpp InputParser.cpp Player.cpp Priest.cpp Scout.cpp Tank.cpp testBoard.cpp -o testBoard
testGame: ;g++ -g $(LDFLAGS) Archer.cpp Board.cpp Fighter.cpp Game.cpp InputParser.cpp Player.cpp Priest.cpp Scout.cpp Tank.cpp testGame.cpp -o testGame

run : ; ./testGame < gameInputs/case1.inp
clean: ; rm -rf ./testGame