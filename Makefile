CCC = g++11

CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11

all : main

main : Board_Tile.h Sliding_Solver.h main.o
	$(CCC) $(CCCFLAGS) -o $@ $^

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f main
