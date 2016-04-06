CCC = g++11

CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11

all : main heap_test

main : Board_Tile.o Sliding_Solver.o main.o
	$(CCC) $(CCCFLAGS) -o $@ $^
heap_test : heap_test.o
	$(CCC) $(CCCFLAGS) -o $@ $^	

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f main heap_test
