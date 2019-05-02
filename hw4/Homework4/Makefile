LDFLAGS=-std=c++11

all: ; g++ $(LDFLAGS) main.cpp Priest.cpp Scout.cpp Fighter.cpp Archer.cpp Tank.cpp Player.cpp Board.cpp Game.cpp InputParser.cpp -o Practice;
run: ; ./Practice 
valgrind: ; valgrind --leak-check=full ./Practice
clean: ; rm -rf Practice;